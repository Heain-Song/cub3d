if ($1)
then
	./cub3D test.cub
else
	valgrind ./cub3D test.cub
fi
