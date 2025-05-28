#include"library.h"

void Library::addBook(const Book& book) {
	books.push_back(book);
}

void Library::printAllBooks(std::ostream& os)const {
	for (const auto& book : books) {
		book.printInfo(os);
		os << "----------------------\n";
	}

}

void Library::searchBook(const std::string &keyword,std::ostream&os)const {
	auto result = std::find_if(books.begin(), books.end(), [&keyword](const Book& b) {
		return b.getIsbn() == keyword ||
			b.getTitle() == keyword ||
			b.getAuthor() == keyword;
		});

	if (result != books.end()) {
		os << "�ҵ���ͼ����Ϣ���£�\n";
		result->printInfo(os);
	}else {
		os << "û���ҵ�ƥ���ͼ�顣\n";
	}
}

bool Library::removeBookByISBN(const std::string&isbn) {
	auto it = std::find_if(books.begin(), books.end(), [&isbn](Book& b) {
		return b.getIsbn() == isbn;
		});
	if (it != books.end()) {
		books.erase(it);
		return true;
	}
	else {
		return false;
	}
}

bool Library::saveToFile(const std::string& filename)const {
	std::ofstream out(filename);

	if (!out)return false;

	for (const auto& book : books) {
		out << book.getIsbn() << '\n'
			<< book.getTitle() << '\n'
			<< book.getAuthor() << '\n'
			<< book.getPublisher() << '\n'
			<< book.getPrice() << '\n';
	}
	return true;
}

bool Library::loadFromFile(const std::string& filename) {
	std::ifstream in(filename);
	if (!in)return false;

	books.clear();// ���ԭ������
	std::string isbn, title, author, publisher;
	double price;

	while (std::getline(in, isbn) &&
		std::getline(in, title) &&
		std::getline(in, author) &&
		std::getline(in, publisher) &&
		in>>price) {
		in.ignore(); // ���� price ��Ļ��з�
		books.emplace_back(isbn, title, author, publisher, price);
	}
	return true;
}