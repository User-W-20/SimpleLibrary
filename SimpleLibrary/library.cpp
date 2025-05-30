#include"library.h"

void Library::addBook(const Book& book,const std::string & category) {
	books.push_back(book);
	categoryBooks[category].insert({ book.getTitle(),Book() });
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

void Library::searchBookFuzzy(const std::string& keyword, std::ostream& os)const {
	std::regex pattern(keyword, std::regex::icase);
	bool found = false;
	for (const auto& book : books) {
		if (std::regex_search(book.getTitle(), pattern) ||
			std::regex_search(book.getAuthor(), pattern)) {
			book.printInfo(os);

			os << "-----------";
			 found = true;
		}

	}
	if (!found) {
		os << "没有找到匹配的图书。\n";
	}
}



void Library::searchBookFuzzySimple(const std::string&keyword,std::ostream& os) {
	auto toLower = [](const std::string& str) {
		std::string result = str;
		std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) {return std::tolower(c); });
		return result;
		};

	std::string keywordLower = toLower(keyword);
	bool found = false;

	for (const auto& book : books) {
		std::string titleLower = toLower(book.getTitle());
		std::string authorLower = toLower(book.getAuthor());
		if (titleLower.find(keywordLower) != std::string::npos ||
			authorLower.find(keywordLower) != std::string::npos) {
			book.printInfo(os);
			os<< "----------------------\n";
			found = true;
		}
	}
	if (!found) {
		os << "没有找到匹配的图书。\n";
	}
}

void Library::addBookWithCategory(const Book& book, const std::string& category) {
	books.push_back(book);
	categoryBooks[category][book.getTitle()] = book;
}

void Library::printBooksByCategory(const std::string& category, std::ostream& os)const {
	auto it = categoryBooks.find(category);
	if (it == categoryBooks.end()) {
		os << "没有找到该分类。\n";
		return;
	}
	os<< "分类 [" <<category<< "] 下的图书：\n";
	for (const auto& [title, book] : it->second) {
		book.printInfo(os);
		os << "----------------------\n";
	}
}
