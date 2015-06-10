#pragma once

class LongNum
{
private:
	int size; 					
	unsigned char* index; 	
	int sign; 					

public:
	LongNum();
	LongNum(const char* String);
	LongNum(const LongNum& RightValue);
	LongNum(int RightValue);

	~LongNum();

	char* TakeStr();

	
	bool OutFile(const char* FileName); 		
	bool InFile(const char* FileName);  		
	bool OutBinFile(const char* FileName); 	
	bool InBinFile(const char* FileName);    


	LongNum& operator=(const LongNum& right);      
	LongNum operator+(const LongNum& right) const; 
	LongNum operator-() const;                     
	LongNum operator-(const LongNum& right) const; 
	LongNum operator*(const LongNum& right) const; 
	LongNum operator/(const LongNum& right) const; 
	LongNum operator%(const LongNum& right) const; 
	LongNum operator^(const LongNum& right) const; 

	bool operator>(const LongNum& B);  
	bool operator>=(const LongNum& B); 
	bool operator<(const LongNum& B);  
	bool operator<=(const LongNum& B); 
	bool operator==(const LongNum& B); 
	bool operator!=(const LongNum& B); 

private:
	void Size_Set(int newSize); 				
	unsigned char & operator[](int i);
	unsigned char operator[](int i) const;
	void DelZero(); 					
	int Compare(const LongNum& B); 			
	void Shift(int s);

	LongNum AddSub(const LongNum& left, const LongNum& right) const;     			
	LongNum Multiply(const LongNum A, const LongNum B) const;           				
	LongNum Divide(const LongNum& A, const LongNum& B, LongNum &remainder) const;  	

};

LongNum Pow(const LongNum& A, const LongNum& B, LongNum& Mod);