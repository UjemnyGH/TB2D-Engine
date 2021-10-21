# Flags
NAME?="TB2DEngineTestCompile"
PR="TB2D_"

compile:
	clear
	echo ">-- Compiling engine --<"
	echo "Executable file name (NAME= to change): ${NAME}"
	echo ""

	g++ -o ${NAME} src/main.cpp src/${PR}square.cpp src/Window/${PR}window.cpp src/Time/${PR}time.cpp src/Buffers/${PR}buffers.cpp -lGL -lGLEW -lglut -lpthread

	echo ">-- Compilation end --<"

	./${NAME}

.SILENT:
