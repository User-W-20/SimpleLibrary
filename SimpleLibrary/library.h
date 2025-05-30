#pragma once
#include"book.h"
#include<vector>
#include<ostream>
#include<algorithm>
#include<fstream>
#include<regex>
#include<cctype>
#include<map>

class Library {
public:
	Library() = default;

	void addBook(const Book&,const std::string &category);//添加图书
	void printAllBooks(std::ostream& os) const;//打印所有图书

	//查找
	void searchBook(const std::string&keyword,std::ostream&os)const;

	//删除
	bool removeBookByISBN(const std::string& isbn);

	bool saveToFile(const std::string& filename)const;//文件保存
	bool loadFromFile(const std::string& filename);//文件加载

	void searchBookFuzzy(const std::string& keyword, std::ostream &os)const;//模糊搜索

	void searchBookFuzzySimple(const std::string&keyword,std::ostream& os);

	void addBookWithCategory(const Book& book, const std::string& category);

	void printBooksByCategory(const std::string& category, std::ostream& os)const;
private:
	std::vector<Book>books;
	std::map<std::string, std::map<std::string, Book>>categoryBooks;
};