#include "../define.h"

template<typename T>
class Object {
private:
	T m_data;
public:
	Object(const T & t) { 
		std::cout << "Constructor!" << std::endl;
		this->m_data = t;
	}

	Object(const Object & obj) {
		std::cout << "Copy constructor" << std::endl;
	}

	~Object(){
		std::cout << "Destructor!" << std::endl;	
	}
	
	void show() {
		std::cout << "Data: " << this->m_data << std::endl; 
	}	
};

void uniquePointer();
void sharedPointer();
void weakPointer();

int main(){
	uniquePointer();
	std::cout << "_________________________________" << std::endl;
	sharedPointer();
	std::cout << "_________________________________" << std::endl;
	weakPointer();
	return 0;
}

std::unique_ptr<Object<int>> getUniquePoiter() {
	std::unique_ptr<Object<int>> p(new Object<int>(0));
	//return p;
	return std::move(p);
}

void uniquePointer() {
	std::cout << "UNIQUE_PTR" << std::endl;
	std::unique_ptr<Object<int>> p1(new Object<int>(1));
	p1->show();

	//std::unique_ptr<Object<int>> p2 = p1;	/*compile error*/
	std::unique_ptr<Object<int>> p2 = std::move(p1);
	std::cout << "address: " << p1.get() << std::endl;
	std::cout << "address: " << p2.get() << std::endl;
	//p1->show(); /*cause core dump*/
	p2->show();

	std::unique_ptr<Object<int>> p3 = getUniquePoiter();
	p3->show();
	std::cout << "address: " << p3.get() << std::endl;	
}
 
void sharedPointer() {
	std::cout << "SHARED_PRT" << std::endl;
	std::shared_ptr<Object<int>> p1(new Object<int>(1));
	
}
	
void weakPointer() {
	std::cout << "WEAK_PTR" << std::endl;	
	std::cout << std::boolalpha << std::endl;
	
	auto sharedPtr = std::make_shared<int> (1995); /*create shared pointer with construct value*/
	std::weak_ptr<int> weakPtr(sharedPtr); /*borrow value of shared pointer*/

	std::cout << "weakPtr.use_count(): " << weakPtr.use_count() << std::endl;
	std::cout << "sharedPtr.use_count(): " << sharedPtr.use_count() << std::endl;
	std::cout << "weakPtr.expired(): " << weakPtr.expired() << std::endl;

	if (std::shared_ptr<int> sharedPtrTmp = weakPtr.lock() ) {
		std::cout << "*sharedPtr: " 				<< *sharedPtr 				<< std::endl;
		std::cout << "sharedPtr.get(): " 			<< sharedPtr.get() 			<< std::endl;
		std::cout << "*sharedPtrTmp: " 				<< *sharedPtrTmp.get() 		<< std::endl;	
		std::cout << "sharedPtrTmp.use_count(): " 	<< sharedPtrTmp.use_count() << std::endl;
	} else { 
		std::cout << "don't get the resource!" 		<< std::endl;
	}	
	
	std::cout << "sharedPtr.use_count(): " << sharedPtr.use_count() << std::endl; 	

	weakPtr.reset();
	
	if (std::shared_ptr<int> sharedPtrTmp = weakPtr.lock() ){
		std::cout << "*sharedPtr: " 				<< *sharedPtr 				<< std::endl;
		std::cout << "sharedPtr.get(): " 			<< sharedPtr.get() 			<< std::endl;
		std::cout << "*sharedPtrTmp: " 				<< *sharedPtrTmp.get() 		<< std::endl;	
		std::cout << "sharedPtrTmp.use_count(): " 	<< sharedPtrTmp.use_count() << std::endl;
	} else { 
		std::cout << "Don't get the resource! " 	<< std::endl;  
	}
}
