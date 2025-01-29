
#include <iostream>

template <typename T>
class unique_ptr
{
public:
	unique_ptr(T* ptr = nullptr) : ptr_{ ptr } {}

	unique_ptr(const unique_ptr<T>& other) = delete;

	unique_ptr(unique_ptr<T>&& other) : ptr_{ other.release()} {}

	~unique_ptr() {
		delete ptr_;
	}

	T& operator*() const {
		return *ptr_;
	}

	unique_ptr<T>& operator=(const unique_ptr<T>& other) = delete;
	unique_ptr<T>& operator=(unique_ptr<T>&& other) {
		if (this != &other) {
			delete ptr_;
			ptr_ = other.release();
		}

		return *this;
	}

	T* get() const {
		return ptr_;
	}

	T* release() {
		T* tmp_ptr = ptr_;
		ptr_ = nullptr;
		return tmp_ptr;
	}

	void reset(T* ptr) {
		delete ptr_;
		ptr_ = ptr;
	}

private:
	T* ptr_{ nullptr };
};

int main()
{
	unique_ptr<int> ptr{new int{5}};
	std::cout << *ptr << '\n';
	std::cout << ptr.get() << '\n';

	auto rawPtr = ptr.release();
	delete rawPtr;
	ptr.reset(new int{ 11 });
	unique_ptr<int> ptr2{std::move(ptr)};
	ptr.reset(new int{ 10 });
	std::cout << *ptr << '\n';
	std::cout << *ptr2 << '\n';

	return 0;
}