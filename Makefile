CFLAGS := -std=c++0x

%:
	$(CXX) $(CFLAGS) $@.cpp

