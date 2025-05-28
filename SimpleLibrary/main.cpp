#include<iostream>
#include"book.h"
#include"library.h"
int main() {
	/*Book book;
	book.readInfo(std::cin);
	book.printInfo(std::cout);*/

	//Library lib;
	//int count = 0;

	//std::cout << "请输入图书数量：";
	//std::cin >> count;
	//std::cin.ignore(); // 清除换行符

	//for (int i = 0; i < count; ++i) {
	//	std::cout << "输入第 " <<(i+1)<< " 本图书信息：" << std::endl;
	//	Book book;
	//	book.readInfo(std::cin);
	//	lib.addBook(book);
	//}
	//std::cout << "\n所有图书信息如下：" << std::endl;
	//	lib.printAllBooks(std::cout);
	/*Book b1;
	b1.readInfo(std::cin);
	lib.addBook(b1);
	
	std::string keyword;
	std::cout << "请输入搜索关键词（ISBN / 作者 / 书名）：\n";
	std::getline(std::cin, keyword);
	
	lib.searchBook(keyword, std::cout);*/
	Library lib;
	/*
	Book book1, book2;

	std::cout << "请输入第一本书信息：\n";
	book1.readInfo(std::cin);
	lib.addBook(book1);

	std::cout << "请输入第二本书信息：\n";
	book2.readInfo(std::cin);
	lib.addBook(book2);

	std::cout << "当前图书馆藏书：\n";
	lib.printAllBooks(std::cout);

	std::string targeIsbn;
	std::cout << "请输入要删除的ISBN：";
	std::getline(std::cin, targeIsbn);

	if (lib.removeBookByISBN(targeIsbn)) {
		std::cout << "删除成功。\n";
	}
	else {
		std::cout << "未找到该ISBN的图书。\n";
	}

	std::cout << "删除后的图书列表：\n";
	lib.printAllBooks(std::cout);*/

	std::string filename = "books.txt";

	// 保存图书
	if (lib.saveToFile(filename)) {
		std::cout << "图书已保存到文件 " << filename << "\n";
	}
	else {
		std::cout << "保存失败\n";
	}

	// 加载图书
	Library newLib;
	if (newLib.loadFromFile(filename)) {
		std::cout << "已从文件加载图书：\n";
		newLib.printAllBooks(std::cout);
	}
	else {
		std::cout << "加载失败\n";
	}
	return 0;
}