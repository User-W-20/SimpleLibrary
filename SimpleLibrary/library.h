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

	void addBook(const Book&,const std::string &category);//���ͼ��
	void printAllBooks(std::ostream& os) const;//��ӡ����ͼ��

	//����
	void searchBook(const std::string&keyword,std::ostream&os)const;

	//ɾ��
	bool removeBookByISBN(const std::string& isbn);

	bool saveToFile(const std::string& filename)const;//�ļ�����
	bool loadFromFile(const std::string& filename);//�ļ�����

	void searchBookFuzzy(const std::string& keyword, std::ostream &os)const;//ģ������

	void searchBookFuzzySimple(const std::string&keyword,std::ostream& os);

	void addBookWithCategory(const Book& book, const std::string& category);

	void printBooksByCategory(const std::string& category, std::ostream& os)const;
private:
	std::vector<Book>books;
	std::map<std::string, std::map<std::string, Book>>categoryBooks;
};