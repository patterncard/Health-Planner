.PHONY: build
build:
	g++ "src/main.cpp" -Iinclude -Llib -lsfml-window -lsfml-graphics -lsfml-system -o "build/main"
run:
	./build/main