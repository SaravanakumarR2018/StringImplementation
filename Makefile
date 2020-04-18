stringImplementationCppExample: stringImplementation.cpp
	g++ -std=c++11 stringImplementation.cpp -o stringImplementationCppExample
	./stringImplementationCppExample

clean:
	rm -f stringImplementationCppExample
