#include<iostream>
#include"book.h"
#include"library.h"
int main() {
	/*Book book;
	book.readInfo(std::cin);
	book.printInfo(std::cout);*/

	//Library lib;
	//int count = 0;

	//std::cout << "������ͼ��������";
	//std::cin >> count;
	//std::cin.ignore(); // ������з�

	//for (int i = 0; i < count; ++i) {
	//	std::cout << "����� " <<(i+1)<< " ��ͼ����Ϣ��" << std::endl;
	//	Book book;
	//	book.readInfo(std::cin);
	//	lib.addBook(book);
	//}
	//std::cout << "\n����ͼ����Ϣ���£�" << std::endl;
	//	lib.printAllBooks(std::cout);
	/*Book b1;
	b1.readInfo(std::cin);
	lib.addBook(b1);
	
	std::string keyword;
	std::cout << "�����������ؼ��ʣ�ISBN / ���� / ��������\n";
	std::getline(std::cin, keyword);
	
	lib.searchBook(keyword, std::cout);*/
	//Library lib;
	/*
	Book book1, book2;

	std::cout << "�������һ������Ϣ��\n";
	book1.readInfo(std::cin);
	lib.addBook(book1);

	std::cout << "������ڶ�������Ϣ��\n";
	book2.readInfo(std::cin);
	lib.addBook(book2);

	std::cout << "��ǰͼ��ݲ��飺\n";
	lib.printAllBooks(std::cout);

	std::string targeIsbn;
	std::cout << "������Ҫɾ����ISBN��";
	std::getline(std::cin, targeIsbn);

	if (lib.removeBookByISBN(targeIsbn)) {
		std::cout << "ɾ���ɹ���\n";
	}
	else {
		std::cout << "δ�ҵ���ISBN��ͼ�顣\n";
	}

	std::cout << "ɾ�����ͼ���б�\n";
	lib.printAllBooks(std::cout);*/

	//std::string filename = "books.txt";

	//// ����ͼ��
	//if (lib.saveToFile(filename)) {
	//	std::cout << "ͼ���ѱ��浽�ļ� " << filename << "\n";
	//}
	//else {
	//	std::cout << "����ʧ��\n";
	//}

	//// ����ͼ��
	//Library newLib;
	//if (newLib.loadFromFile(filename)) {
	//	std::cout << "�Ѵ��ļ�����ͼ�飺\n";
	//	newLib.printAllBooks(std::cout);
	//}
	//else {
	//	std::cout << "����ʧ��\n";
	//}

	/*lib.addBook(Book("9787302293286", "C++ Primer", "Stanley Lippman", "���ӹ�ҵ������", 88.00));
	lib.addBook(Book("9787115546082", "Effective C++", "Scott Meyers", "��е��ҵ������", 66.00));
	lib.addBook(Book("1234567890", "Python����", "����", "�廪��ѧ������", 59.00));*/

	/*std::cout << "ģ������������ 'c\\+\\+'��ƥ�� C++ Primer��\n";
	lib.searchBookFuzzy("c\\+\\+", std::cout);

	std::cout << "\nģ������������ 'Scott'��ƥ�����ߣ�\n";
	lib.searchBookFuzzy("Scott", std::cout);

	std::cout << "\nģ������������ '����'��ƥ�����ģ�\n";
	lib.searchBookFuzzy("����", std::cout);

	std::cout << "\nģ������������ 'Java'����ƥ�䣩\n";*/
	//lib.searchBookFuzzy("Java", std::cout);
	//lib.searchBookFuzzySimple(std::cout, std::cin);
	return 0;
}