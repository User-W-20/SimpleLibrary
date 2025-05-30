#include<iostream>
#include<sstream>
#include<limits>
#include"book.h"
#include"library.h"
int main() {
	Library lib;
	

	// 1. 加载数据
	if (lib.loadFromFile("books.txt")) {
		std::cout << "图书数据加载成功。\n";
	}
	else {
		std::cout << "未找到图书文件，开始创建新库。\n";
	}

	// 简单演示：预置添加几本书（如果你不希望重复添加可以加条件）
	lib.addBook(Book("9787302293286", "C++ Primer", "Stanley Lippman", "电子工业出版社", 88), "编程");
	lib.addBook(Book("9787115546082", "Effective C++", "Scott Meyers", "机械工业出版社", 66), "编程");
	lib.addBook(Book("1234567890", "Python入门", "张三", "清华大学出版社", 59), "编程");
	lib.addBook(Book("9876543210", "思考快与慢", "Daniel Kahneman", "中信出版社", 49), "心理学");

	int choice;
	do {
		std::cout << "\n===== 图书管理系统菜单 =====\n";
		std::cout << "1. 打印全部图书\n";
		std::cout << "2. 精确查找图书\n";
		std::cout << "3. 模糊查找图书\n";
		std::cout << "4. 删除图书\n";
		std::cout << "5. 按分类打印图书\n";
		std::cout << "6. 保存并退出\n";
		std::cout << "请输入选项（1-6）：";

		std::cin >> choice;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清空输入缓冲

		switch (choice){
		case 1: {
			std::cout << "\n当前图书库内容：\n";
			lib.printAllBooks(std::cout);
			break;
		}
		case 2: {
			std::string keyword;
			std::cout << "\n请输入关键词（ISBN/书名/作者）：";
			std::getline(std::cin, keyword);
			lib.searchBook(keyword, std::cout);
			break;
		}
		case 3: {
			std::string keyword;
			std::cout << "\n请输入关键词（书名/作者，模糊匹配）：";
			std::getline(std::cin, keyword);
			lib.searchBookFuzzySimple(keyword, std::cout);
			break;
		}
		case 4: {
			std::string isbn;
			std::cout << "\n请输入要删除的图书ISBN：";
			std::getline(std::cin, isbn);
			if (lib.removeBookByISBN(isbn)) {
				std::cout << "图书删除成功。\n";
			}
			else {
				std::cout << "未找到图书。\n";
			}
			break;
		}
		case 5: {
			std::string category;
			std::cout << "\n请输入分类名：";
			std::getline(std::cin, category);
			lib.printBooksByCategory(category, std::cout);
			break;
		}
		case 6: {
			if (lib.saveToFile("books.txt")) {
				std::cout << "图书保存成功，程序退出。\n";
			}
			else {
				std::cout << "保存失败，程序退出。\n";
			}
			break;
		}
		default:
			std::cout << "无效的选项，请重新输入。\n";
			break;
		}
	} while (choice != 6);

	return 0;
}