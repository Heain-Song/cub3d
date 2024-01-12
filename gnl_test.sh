if ($1)
then 
	./cub3D maps/minimalist.cub
	#./cub3D double_tex.cub
else
	valgrind --leak-check=full ./cub3D maps/minimalist.cub
	#valgrind --leak-check=full ./cub3D double_tex.cub
fi
