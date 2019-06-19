# fillit_domi

In file "ft_readtet.c" we have :
  1. function "read_file" calls the below functions :
      1.1 function "check_tet" which also calls :
          1.1.1 function "tetr_calc"        (in file "ft_isvalid.c")
				  1.1.2 function "check_neighbours" (in file "ft_isvalid.c")
      1.2 function "shift_to_topleft" (in file "ft_shiftsave.c")
      1.3 function "save_tolist" (in file "ft_shiftsave.c")
