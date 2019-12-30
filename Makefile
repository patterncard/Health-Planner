.PHONY: build
build:
	g++ "src/main.cpp" -Iinclude -Llib -lsfml-window -o "build/main"
run:
	./build/main