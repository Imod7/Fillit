# fillit_domi ![fillit](https://img.shields.io/badge/typesafe-check-blue.svg)

In file "ft_readtet.c" we have :
- function "read_file" calls the below functions :
  - function "check_tet" which also calls :
    - function "tetr_calc"        (in file "ft_isvalid.c")
    - function "check_neighbours" (in file "ft_isvalid.c")
  - function "shift_to_topleft" (in file "ft_shiftsave.c")
  - function "save_tolist" (in file "ft_shiftsave.c")
