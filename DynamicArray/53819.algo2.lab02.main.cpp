// ALGO2 IS1 224B LAB02
// ILLIA KARMAZIN
// ki53819@zut.edu.pl

#include <iostream>

template <class T>
class Dynamic_Array
{
public:
	Dynamic_Array()=default;
	~Dynamic_Array();
	int Size{ 0 }, Max_Size{ 1 }, Expansion{ 2 };
	T* value = new T[Max_Size];
	void Add(T Value);
	T operator[](int index)
	{
		if (index < 0 || index >= this->Size)
			std::cout << "Wrong index" << std::endl;
		else
			return this->value[index];
	}
	void Get_by_index(int index);
	void Change(int index, T Value);
};

template <class T>
Dynamic_Array<T>::~Dynamic_Array(){}

template <class T>
void Dynamic_Array<T>::Add(T Value)
{
	if (this->Size != this->Max_Size)
	{
		this->value[this->Size] = Value;
		++this->Size;
	}
	else
	{
		this->Max_Size *= this->Expansion;
		T* copy_values = this->value;
		this->value = nullptr;
		this->value = new T[this->Max_Size];
		for (int index = 0; index < this->Size; ++index)
		{
			this->value[index] = copy_values[index];
		}
		this->value[this->Size] = Value;
		++this->Size;
		copy_values = nullptr;
		delete[] copy_values;
	}
}

template<class T>
void Dynamic_Array<T>::Get_by_index(int index)
{
	if (index < 0 || index >= this->Size)
		std::cout << "Wrong index" << std::endl;
	else
		std::cout << "Value : " << (*this)[index] << std::endl;
}

template<class T>
void Dynamic_Array<T>::Change(int index, T Value)
{
	if (index < 0 || index >= this->Size)
		std::cout << "Wrong index" << std::endl;
	else
		this->value[index] = Value;
}

int main()
{
	Dynamic_Array<int>* array = new Dynamic_Array<int>();
	return 0;
}
