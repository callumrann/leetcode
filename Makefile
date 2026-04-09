.PHONY: clean

CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -O0 -fsanitize=address -g

%: src/%.cpp
	$(CXX) $< $(CXXFLAGS) -o $@

clean:
	rm -f p*
