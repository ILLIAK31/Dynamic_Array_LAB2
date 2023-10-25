// ALGO2 IS1 224B LAB02
// ILLIA KARMAZIN
// ki53819@zut.edu.pl
#include <iostream>
#include <time.h>

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
			std::cout << "Wrong index\n" << std::endl;
		else
			return this->value[index];
	}
	void Get_by_index(int index);
	void Change(int index, T Value);
	void Clear();
	void To_String(int obj_size);
	void Bubble_Sort();
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
		std::cout << "Wrong index\n" << std::endl;
	else
		std::cout << "Value : " << (*this)[index] << std::endl;
}

template<class T>
void Dynamic_Array<T>::Change(int index, T Value)
{
	if (index < 0 || index >= this->Size)
		std::cout << "Wrong index\n" << std::endl;
	else
		this->value[index] = Value;
}

template<class T>
void Dynamic_Array<T>::Clear()
{
	for (int index = 0; index < this->Size; ++index) {this->value[index] = NULL;}
	delete [] this->value;
	this->value = nullptr;
	this->Size = 0;
	this->Max_Size = 1;
}

template<class T>
void Dynamic_Array<T>::To_String(int obj_size)
{
	if (obj_size < 0 || obj_size > this->Size)
		std::cout << "Wrong size of objects\n";
	else
	{
		std::cout << "\t| Dynamic Array |\n";
		std::cout << "| Size : " << this->Size << " | Max Size : " << this->Max_Size << " | Address of DA : " << this << " | Address of array : " << this->value << " |\n";
		for (int index = 0; index < obj_size; ++index)
		{
			std::cout << "| Object " << index + 1 << " : " << this->value[index] << " |\n";
		}
	}
}

template<class T>
void Dynamic_Array<T>::Bubble_Sort()
{
	T copy;
	for (int index1 = 0; index1 < this->Size - 1; ++index1)
	{
		for (int index2 = 0; index2 < this->Size - index1 - 1; ++index2)
		{
			if (this->value[index2] > this->value[index2 + 1])
			{
				copy = this->value[index2 + 1];
				this->value[index2+1] = this->value[index2];
				this->value[index2] = copy;
			}
		}
	}
}

int main()
{
	Dynamic_Array<int>* array = new Dynamic_Array<int>();
	int Num{ 0 }, size{ 0 };
	double average_per_object{ 0 }, worst_time{ 0 };
	clock_t timer1 = clock();
	for (int index1 = 0; index1 < pow(10, 5); ++index1)
	{
		Num = rand() % 1000;
		clock_t timer3 = clock();
		array->Add(Num);
		clock_t timer4 = clock();
		average_per_object += (timer4 - timer3) / (double)CLOCKS_PER_SEC;
		++size;
		if (((timer4 - timer3) / (double)CLOCKS_PER_SEC) > worst_time)
		{
			std::cout << "| New worst time from " << worst_time;
			worst_time = ((timer4 - timer3) / (double)CLOCKS_PER_SEC);
			std::cout << " s to " << worst_time << " s\n";
		}
	}
	clock_t timer2 = clock();
	array->To_String(array->Size);
	average_per_object /= size;
	average_per_object *= 1000;
	std::cout << "| Full time : " << ((timer2 - timer1) / (double)CLOCKS_PER_SEC) << " s | Average time per object : " << average_per_object << " ms |\n";
	array->Clear();
	delete array;
	return 0;
}
