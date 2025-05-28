#pragma once
#include"book.h"
#include<vector>
#include<ostream>
#include<algorithm>
#include<fstream>
class Library {
public:
	Library() = default;

	void addBook(const Book&);//添加图书
	void printAllBooks(std::ostream& os) const;//打印所有图书

	//查找
	void searchBook(const std::string&keyword,std::ostream&os)const;

	//删除
	bool removeBookByISBN(const std::string& isbn);

	bool saveToFile(const std::string& filename)const;//文件保存
	bool loadFromFile(const std::string& filename);//文件加载
private:
	std::vector<Book>books;
};