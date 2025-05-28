#include"book.h"
#include<iostream>



std::string Book::getIsbn()const { return isbn; }
std::string Book::getTitle()const { return title; }
std::string Book::getAuthor()const { return author; }
std::string Book::getPublisher()const { return publisher; }
double Book::getPrice()const { return price; }

std::istream& Book::readInfo(std::istream& in) {
   
    
        std::cout << " 请输入ISBN： " << '\n';
        std::getline(in, isbn);
        std::cout << "请输入书名："<<'\n';
        std::getline(in, title);
        std::cout << "请输入作者：" << '\n';
        std::getline(in, author);
        std::cout << "请输入出版社：" << '\n';
        std::getline(in, publisher);
        std::cout << "请输入价格：" << '\n';
        std::string priceStr;
        std::getline(in, priceStr);
        price = std::stod(priceStr);

    
    
        return in;
}

std::ostream& Book::printInfo(std::ostream& os)const{
    os << "ISBN: " << isbn << "\n"
        << "书名: " << title << "\n"
        << "作者: " << author << "\n"
        << "出版社: " << publisher << "\n"
        << "价格: " << price << " 元" << std::endl;
    return os;
}

