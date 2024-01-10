if ($1)
then 
	#./cub3D test.cub
	./cub3D double_tex.cub
else
	#valgrind ./cub3D test.cub
	valgrind --leak-check=full ./cub3D double_tex.cub
fi
