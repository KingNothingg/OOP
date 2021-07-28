//Тарпанов Даниил, М8О-204Б-19 ЛР №3
//Вариант №7, создать класс BitString для работы с 128-битовыми строками. Реализовать традиционные операции
//для работы с битами, сдвиги и операторы сравнения.

#ifndef BITSTRING_CPP
#define BITSTRING_CPP

#include <iostream>

class BitString {
    private:
        unsigned long long first;
        unsigned long long second;
    public:
        BitString();
        BitString(unsigned long long number);
        ~BitString() {}
        BitString& operator=(unsigned long long value);
        BitString& operator=(BitString other);
        unsigned int BitCount()const;
        void Print() const;

        friend BitString operator&(const BitString& lhs,const BitString& rhs);
        friend BitString operator|(const BitString& lhs,const BitString& rhs);
        friend BitString operator^(const BitString& lhs,const BitString& rhs);
        friend BitString operator~(const BitString& bs);
        friend BitString operator<<(const BitString& bs, unsigned int n);
        friend BitString operator>>(const BitString& bs, unsigned int n);

        inline bool operator==(const BitString& other) {
			return this->BitCount() == other.BitCount();
		}
        inline bool operator<(const BitString& other) {
			return this->BitCount() < other.BitCount();
		}
        inline bool operator>(const BitString& other) {
			return this->BitCount() > other.BitCount();
		}
};


BitString::BitString(){
	first = 0;
	second = 0;
}
BitString::BitString(unsigned long long number){
	second = number;
	first = 0;
}
unsigned int BitString::BitCount() const {
	unsigned int count = 0;
	unsigned long long temp;
	unsigned int bitsize = sizeof(first) * 8;
	temp=first;
	for(unsigned int i = 0; i < bitsize; ++i){
		count += temp & 1u;
		temp >>= 1;
	}
	temp = second;
	for(unsigned int i = 0; i < bitsize; ++i){
		count += temp & 1u;
		temp >>= 1;
	}
	return count;
}

BitString operator "" _bs(unsigned long long value) {
	return BitString(value);
}

void BitString::Print() const {
	if(this->first != 0 && this->second != 0)
	std::cout << this->first << this->second << '\n';
	else if(this->second != 0)
	std::cout << this->second << '\n';
	else if(this->first == 0 && this -> second == 0)
	std::cout << "0\n";
}

BitString operator&(const BitString& left,const BitString& right){
	BitString result;
	result.first = left.first & right.first;
	result.second = left.second & right.second;
	return result;
}
BitString operator|(const BitString& left,const BitString& right){
	BitString result;
	result.first = left.first | right.first;
	result.second = left.second | right.second;
	return result;
}
BitString operator^(const BitString& left,const BitString& right){
	BitString result;
	result.first = left.first ^ right.first;
	result.second = left.second ^ right.second;
	return result;
}
BitString operator~(const BitString& bs){
	BitString result;
	result.first =~ bs.first;
	result.second =~ bs.second;
	return result;
}
BitString operator<<(const BitString& bs, unsigned int n){
	BitString result;
	if(n == 0){
		result = bs;
		return result;
	}
	unsigned int bitsize = sizeof(bs.first) * 8;
	if(n > bitsize * 2 - 1){
		return result;
	}
	if(n > bitsize - 1){
		result.first = bs.second << (n - bitsize);
		result.second = 0;
		return result;
	}
	unsigned long long temp = bs.second >> (bitsize - n);
	result.first = bs.first << n;
	result.first += temp;   
	result.second = bs.second << n;
	return result;

}
BitString operator>>(const BitString& bs, unsigned int n){
	BitString result;
		if(n == 0){
		result = bs;
		return result;
	}
	unsigned int bitsize = sizeof(bs.first) * 8;
	if(n > bitsize * 2 - 1){
		return result;
	}
	if(n>bitsize-1){
		result.second = bs.first >> (n - bitsize);
		result.first = 0;
		return result;
	}
	unsigned long long temp = bs.first << (bitsize - n);
	result.second=bs.second >> n;
	result.second += temp;
	result.first=bs.first >> n;
	return result;
}
BitString& BitString::operator=(unsigned long long value){
	this->first = 0;
	this->second = value;
	return *this;
}
BitString& BitString::operator=(BitString other){
	this->first = other.first;
	this->second = other.second;
	return *this;
}


#endif