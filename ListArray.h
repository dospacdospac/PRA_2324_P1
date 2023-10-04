class ListArray<T> : public List {
        private:
                int max;
                int n;    
                static const int MINSIZE;
                void resize(int new_size);
	public:
		ListArray(){
			*T arr[MINSIZE];
			int max = size();
			int n = 0;
		}

