all:dyn_arr.cpp
	@clear
	@echo ========== START  COMPILATION ===========
#	@./loading.sh
	@echo
	@ctags -R .
	@g++ -g dyn_arr.cpp -o dyn_arr
	@echo =========== PROGRAM " "RUNING ===========
	@echo
	@./loading.sh
	@echo
	@echo
	@./dyn_arr
	@echo
	@echo
	@echo
	@echo ======= RUN COMPLETED SUCCESSFULLY =======
clean:
	rm dyn_arr
	
