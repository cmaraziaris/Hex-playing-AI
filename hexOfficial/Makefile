
CC = gcc
FLAGS = -c

objects = main.o Cont.o createInitFree.o generalFunctions.o Level.o \
 NewGame.o Play.o SaveLoadQuit.o Swap.o letserrorhandle.o \
 commandLine.o lists.o bestMove.o forceMoves.o openingMoves.o \
 dynDiff.o letsprint.o letsswap.o letswin.o \
 abPruning.o letseval.o dijkstra.o list_operations.o bridges.o

basic_headers = ./Hex/Basic_Headers/globals.h ./Hex/Basic_Headers/types.h 

Hexie : $(objects)
	$(CC) $(objects) -o hex
	rm -f *.o

main.o : ./Hex/main_Related/main.c ./Hex/main_Related/main_Header.h $(basic_headers)
	$(CC) $(FLAGS) ./Hex/main_Related/main.c

Cont.o : ./Hex/main_Related/In-Game_Commands/Cont.c ./Hex/main_Related/In-Game_Commands/Cont.h $(basic_headers)
	$(CC) $(FLAGS)	./Hex/main_Related/In-Game_Commands/Cont.c

createInitFree.o : ./Hex/main_Related/In-Game_Commands/createInitFree.c ./Hex/main_Related/In-Game_Commands/createInitFree.h $(basic_headers)
	$(CC) $(FLAGS)	./Hex/main_Related/In-Game_Commands/createInitFree.c

generalFunctions.o : ./Hex/main_Related/In-Game_Commands/generalFunctions.c ./Hex/main_Related/In-Game_Commands/generalFunctions.h $(basic_headers)
	$(CC) $(FLAGS)	./Hex/main_Related/In-Game_Commands/generalFunctions.c

Level.o : ./Hex/main_Related/In-Game_Commands/Level.c ./Hex/main_Related/In-Game_Commands/Level.h $(basic_headers)
	$(CC) $(FLAGS)	./Hex/main_Related/In-Game_Commands/Level.c

NewGame.o : ./Hex/main_Related/In-Game_Commands/NewGame.c ./Hex/main_Related/In-Game_Commands/NewGame.h $(basic_headers)
	$(CC) $(FLAGS)	./Hex/main_Related/In-Game_Commands/NewGame.c

Play.o : ./Hex/main_Related/In-Game_Commands/Play.c ./Hex/main_Related/In-Game_Commands/Play.h $(basic_headers)
	$(CC) $(FLAGS)	./Hex/main_Related/In-Game_Commands/Play.c

SaveLoadQuit.o : ./Hex/main_Related/In-Game_Commands/SaveLoadQuit.c ./Hex/main_Related/In-Game_Commands/SaveLoadQuit.h $(basic_headers)
	$(CC) $(FLAGS)	./Hex/main_Related/In-Game_Commands/SaveLoadQuit.c

Swap.o : ./Hex/main_Related/In-Game_Commands/Swap.c ./Hex/main_Related/In-Game_Commands/Swap.h $(basic_headers)
	$(CC) $(FLAGS)	./Hex/main_Related/In-Game_Commands/Swap.c

letserrorhandle.o : ./Hex/main_Related/Error_Handling/letserrorhandle.c ./Hex/main_Related/Error_Handling/letserrorhandle.h $(basic_headers)
	$(CC) $(FLAGS)	./Hex/main_Related/Error_Handling/letserrorhandle.c

commandLine.o : ./Hex/main_Related/Command_Line/commandLine.c ./Hex/main_Related/Command_Line/commandLine.h $(basic_headers)
	$(CC) $(FLAGS)	./Hex/main_Related/Command_Line/commandLine.c

dynDiff.o : ./Hex/Difficulty_Modifier/dynDiff.c ./Hex/Difficulty_Modifier/dynDiff.h $(basic_headers)
	$(CC) $(FLAGS)	./Hex/Difficulty_Modifier/dynDiff.c

letsprint.o : ./Hex/Interface_Print/letsprint.c ./Hex/Interface_Print/letsprint.h $(basic_headers)
	$(CC) $(FLAGS)	./Hex/Interface_Print/letsprint.c

letsswap.o : ./Hex/Swap_Move/letsswap.c ./Hex/Swap_Move/letsswap.h $(basic_headers)
	$(CC) $(FLAGS)	./Hex/Swap_Move/letsswap.c

letswin.o : ./Hex/Win_Check/letswin.c ./Hex/Win_Check/letswin.h $(basic_headers)
	$(CC) $(FLAGS)	./Hex/Win_Check/letswin.c

lists.o : ./Hex/Win_Check/List_functions/lists.c ./Hex/Win_Check/List_functions/lists.h $(basic_headers)
	$(CC) $(FLAGS)	./Hex/Win_Check/List_functions/lists.c

bestMove.o : ./Hex/AI/bestMove.c ./Hex/AI/bestMove.h $(basic_headers)
	$(CC) $(FLAGS)	./Hex/AI/bestMove.c

forceMoves.o : ./Hex/AI/Forced_Moves/forceMoves.c ./Hex/AI/Forced_Moves/forceMoves.h $(basic_headers)
	$(CC) $(FLAGS)	./Hex/AI/Forced_Moves/forceMoves.c

openingMoves.o : ./Hex/AI/Forced_Moves/openingMoves.c ./Hex/AI/Forced_Moves/openingMoves.h $(basic_headers)
	$(CC) $(FLAGS)	./Hex/AI/Forced_Moves/openingMoves.c

abPruning.o : ./Hex/AI/AB_pruning/abPruning.c ./Hex/AI/AB_pruning/abPruning.h $(basic_headers)
	$(CC) $(FLAGS)	./Hex/AI/AB_pruning/abPruning.c

letseval.o : ./Hex/AI/AB_pruning/Evaluation_Function/letseval.c ./Hex/AI/AB_pruning/Evaluation_Function/letseval.h $(basic_headers)
	$(CC) $(FLAGS)	./Hex/AI/AB_pruning/Evaluation_Function/letseval.c

dijkstra.o : ./Hex/AI/AB_pruning/Evaluation_Function/Dijkstra_Shortest_Path/dijkstra.c ./Hex/AI/AB_pruning/Evaluation_Function/Dijkstra_Shortest_Path/dijkstra.h $(basic_headers)
	$(CC) $(FLAGS)	./Hex/AI/AB_pruning/Evaluation_Function/Dijkstra_Shortest_Path/dijkstra.c 

list_operations.o : ./Hex/AI/AB_pruning/Evaluation_Function/Dijkstra_Shortest_Path/list_operations.c ./Hex/AI/AB_pruning/Evaluation_Function/Dijkstra_Shortest_Path/list_operations.h $(basic_headers)
	$(CC) $(FLAGS)	./Hex/AI/AB_pruning/Evaluation_Function/Dijkstra_Shortest_Path/list_operations.c

bridges.o : ./Hex/AI/AB_pruning/Evaluation_Function/Bridges_Functions/bridges.c ./Hex/AI/AB_pruning/Evaluation_Function/Bridges_Functions/bridges.h $(basic_headers)
	$(CC) $(FLAGS)	./Hex/AI/AB_pruning/Evaluation_Function/Bridges_Functions/bridges.c
