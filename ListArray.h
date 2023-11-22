#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

 private:
  T* arr;
  int max;
  int n;
  static const int MINSIZE = 2;

  void resize(int news){
        T* new_arr = new T[news];
	for(int i=0; i< max; i++){
	   new_arr[i] = arr[i]; 
	}
	delete [] arr;
        arr = new_arr;
	max = news;
      }
  // miembros privados

 public:
  ListArray(){
    max = MINSIZE;
    arr = new T[max];
    n = 0;
  }
  
  ~ListArray(){
    delete[] arr;
  }
  
  T operator[](int pos){
    if(pos < 0 || pos > arr.size() -1){
      throw std::out_of_range("Fuera del rango");
    }
    else{
      return arr[pos];
    }
  }
  
  friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
    out << "List -> [";
    for (int i = 0; i < list.size(); i++) {
        out << list.get(i) << " ";
    }
    out << "]";
    return out;

  }

  void insert(int pos, T e) override{
      	if(pos < 0 || pos > size()){
	  throw std::out_of_range("La posición no es válida");
        }
	if(size() >= max){
          resize(n*2);
        }
	for(int i=n; i>pos;i--){
	  arr[i] = arr[i-1];

	}
	arr[pos]= e;
	n++;
      }


  void append(T e) override{
        insert(n, e);
      }

  void prepend(T e) override{
      	insert(0, e);
      }

  T remove(int pos) override{
        if(pos < 0 || pos >= size()){
	  throw std::out_of_range("La posición no es válida");
        }
	T valor = arr[pos];
	for(int i=pos;i<n;i++){
	   arr[i] = arr[i+1];
	}
	n--;
	if(size() <= max/2){
          resize(n/2);
        }
	return valor;
	
      }

  T get(int pos) const override{
	if(pos < 0 || pos >= size()){
	  throw std::out_of_range("La posición no es válida");
         }
         return arr[pos];
      }

  int search(T e) const override{
        for(int i=0;i<n;i++){
	   if(arr[i]==e){
	      return i;
	   }
	}
	return -1;	
      }

  bool empty() const override{
        return (n == 0);
        
      }
      
  int size() const override {
     
    return n;
  }

  

  
  // miembros públicos, incluidos los heredados de List<T>
    
};


