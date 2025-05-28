#pragma once
#include<string>
#include<vector>
class Book
{
	
public:
	//����
	Book(const std::string& isbn,
		const std::string& title,
		const std::string& author,
		const std::string& publisher,
		double price) :isbn(isbn), title(title), author(author), publisher(publisher), price(price) {
	}

	Book() = default;
	//Getter ����
	std::string getIsbn()const;
	std::string getTitle()const;
	std::string getAuthor()const;
	std::string getPublisher()const;
	double getPrice()const;

	//��ȡ����ͼ����Ϣ
	std::istream& readInfo(std::istream& in);

	//��ӡͼ����Ϣ
	std::ostream& printInfo(std::ostream& os)const;
private:
	std::string isbn;
	std::string title;
	std::string author;
	std::string publisher;
	double price=0.0;


};