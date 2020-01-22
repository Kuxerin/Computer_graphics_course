all:
	
	gcc -Iinclude/ src/main.c src/utils.c src/init.c src/callbacks.c src/camera.c src/textures.c src/lights.c src/skybox.c src/help.c -lobj -lSOIL -lglut32 -lopengl32 -lglu32 -lm -o main.exe

