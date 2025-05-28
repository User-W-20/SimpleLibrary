#include"book.h"
#include<iostream>



std::string Book::getIsbn()const { return isbn; }
std::string Book::getTitle()const { return title; }
std::string Book::getAuthor()const { return author; }
std::string Book::getPublisher()const { return publisher; }
double Book::getPrice()const { return price; }

std::istream& Book::readInfo(std::istream& in) {
   
    
        std::cout << " ������ISBN�� " << '\n';
        std::getline(in, isbn);
        std::cout << "������������"<<'\n';
        std::getline(in, title);
        std::cout << "���������ߣ�" << '\n';
        std::getline(in, author);
        std::cout << "����������磺" << '\n';
        std::getline(in, publisher);
        std::cout << "������۸�" << '\n';
        std::string priceStr;
        std::getline(in, priceStr);
        price = std::stod(priceStr);

    
    
        return in;
}

std::ostream& Book::printInfo(std::ostream& os)const{
    os << "ISBN: " << isbn << "\n"
        << "����: " << title << "\n"
        << "����: " << author << "\n"
        << "������: " << publisher << "\n"
        << "�۸�: " << price << " Ԫ" << std::endl;
    return os;
}

