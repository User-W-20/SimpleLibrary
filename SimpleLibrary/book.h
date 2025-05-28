#pragma once
#include<string>
#include<vector>
class Book
{
	
public:
	//构造
	Book(const std::string& isbn,
		const std::string& title,
		const std::string& author,
		const std::string& publisher,
		double price) :isbn(isbn), title(title), author(author), publisher(publisher), price(price) {
	}

	Book() = default;
	//Getter 函数
	std::string getIsbn()const;
	std::string getTitle()const;
	std::string getAuthor()const;
	std::string getPublisher()const;
	double getPrice()const;

	//获取输入图书信息
	std::istream& readInfo(std::istream& in);

	//打印图书信息
	std::ostream& printInfo(std::ostream& os)const;
private:
	std::string isbn;
	std::string title;
	std::string author;
	std::string publisher;
	double price=0.0;


};