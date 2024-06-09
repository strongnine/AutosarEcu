VPATH  = ./obj
# BSW 路径
BSW_PATH  = ../BSW:../BSW/BSW_IF
# ASW 路径
ASW_PATH  = ../ASW:../ASW/ASW_APP1
# RTE 路径
RTE_PATH = ../RTE/RTE_APP1/RTE_APP1_EcuM:../RTE/RTE_APP1/RTE_APP1_NvmM:../RTE/RTE_APP1/RTE_APP1_CanRx:../RTE/RTE_APP1/RTE_APP1_CanTx
# 项目路径
PROJECT_PATH = ./
OBJ_PATH = ./obj

C_INCLUDE_PATH = $(PROJECT_PATH):$(BSW_PATH):$(ASW_PATH):$(RTE_PATH)
export C_INCLUDE_PATH

objects = main.o rte_app1_state_manage.o \
	rte_app1_nvm_manage.o rte_app1_can_rx.o \
	bsw_if.o

main: $(objects)
	gcc -o ./main ./obj/*.o
main.o: 
	gcc -c -o ./obj/main.o ./main.c
bsw_if.o:
	gcc -c -o ./obj/bsw_if.o ../BSW/BSW_IF/bsw_if.c
rte_app1_state_manage.o:
	gcc -c -o ./obj/rte_app1_state_manage.o ../RTE/RTE_APP1/RTE_APP1_EcuM/rte_app1_state_manage.c
rte_app1_nvm_manage.o:
	gcc -c -o ./obj/rte_app1_nvm_manage.o ../RTE/RTE_APP1/RTE_APP1_NvmM/rte_app1_nvm_manage.c
rte_app1_can_rx.o:
	gcc -c -o ./obj/rte_app1_can_rx.o ../RTE/RTE_APP1/RTE_APP1_CanRx/rte_app1_can_rx.c

.PHONY: clean
clean:
	rm ./obj/*.o
	rm main