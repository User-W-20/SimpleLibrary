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
		os << "找到的图书信息如下：\n";
		result->printInfo(os);
	}else {
		os << "没有找到匹配的图书。\n";
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

	books.clear();// 清空原有数据
	std::string isbn, title, author, publisher;
	double price;

	while (std::getline(in, isbn) &&
		std::getline(in, title) &&
		std::getline(in, author) &&
		std::getline(in, publisher) &&
		in>>price) {
		in.ignore(); // 忽略 price 后的换行符
		books.emplace_back(isbn, title, author, publisher, price);
	}
	return true;
}