#pragma once
#include"book.h"
#include<vector>
#include<ostream>
#include<algorithm>
#include<fstream>
class Library {
public:
	Library() = default;

	void addBook(const Book&);//���ͼ��
	void printAllBooks(std::ostream& os) const;//��ӡ����ͼ��

	//����
	void searchBook(const std::string&keyword,std::ostream&os)const;

	//ɾ��
	bool removeBookByISBN(const std::string& isbn);

	bool saveToFile(const std::string& filename)const;//�ļ�����
	bool loadFromFile(const std::string& filename);//�ļ�����
private:
	std::vector<Book>books;
};