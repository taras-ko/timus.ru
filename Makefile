CXXFLAGS = -std=c++0x -g

%:
	$(CXX) $(CXXFLAGS) $@.cpp
