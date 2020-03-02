#include "proj1.h"
#include "computer.h"
#include "string.h"
#include <iostream>
using namespace std;
/**
 * made by AnDJ,2017,12,18
 * the mode is stand for operation of the next including disassemble and simulateInstr
 * mode == true is disassemble,mode == false is simulateInstr
 */

//R-type
//add $1, $2, $3    $1=$2+$3
//    rd  rs  rt    rd=rs+rt
void add_Intro(bool mode, unsigned int introduction, char*& outChar,
               int &changedReg,int &changedMem,Computer mips){
    int rs=(introduction<<6>>27);
    int rt=introduction<<11>>27;
    int rd=introduction<<16>>27;
    if(mode){
        strcat(outChar,"add\t");
        char registerName[3];
        strcat(outChar,"$");
        sprintf(registerName,"%d",rd);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rs);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rt);
        strcat(outChar,registerName);
    }else{
        mips->registers[rd]=mips->registers[rs]+mips->registers[rt];
        int temp=mips->registers[rd];
        if(temp!=mips->registers[rd])
            changedReg=rd;
        else
            changedReg=-1;
        changedMem=-1;
        mips->pc+=4;
    }
}
void addu_Intro(bool mode, unsigned int introduction, char*& outChar ,int &changedReg,int &changedMem,Computer mips){
    int rs=(introduction<<6>>27);
    int rt=introduction<<11>>27;
    int rd=introduction<<16>>27;
    if(mode){
        strcat(outChar,"addu\t");

        char registerName[3];
        strcat(outChar,"$");
        sprintf(registerName,"%d",rd);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rs);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rt);
        strcat(outChar,registerName);
    }else{

        mips->registers[rd]=(unsigned int)mips->registers[rs]+(unsigned int)mips->registers[rt];
        int temp=mips->registers[rd];
        if(temp!=mips->registers[rd])
            changedReg=rd;
        else
            changedReg=-1;
        changedMem=-1;
        mips->pc+=4;
    }
}
void sub_Intro(bool mode, unsigned int introduction, char*& outChar ,int &changedReg,int &changedMem,Computer mips){
    int rs=(introduction<<6>>27);
    int rt=introduction<<11>>27;
    int rd=introduction<<16>>27;
    if(mode){
        strcat(outChar,"sub\t");
        char registerName[3];
        strcat(outChar,"$");
        sprintf(registerName,"%d",rd);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rs);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rt);
        strcat(outChar,registerName);
    }else{
        mips->registers[rd]=mips->registers[rs]-mips->registers[rt];
        int temp=mips->registers[rd];
        if(temp!=mips->registers[rd])
            changedReg=rd;
        else
            changedReg=-1;
        changedMem=-1;
        mips->pc+=4;
    }
}
void subu_Intro(bool mode, unsigned int introduction, char*& outChar ,int &changedReg,int &changedMem,Computer mips){
    int rs=(introduction<<6>>27);
    int rt=introduction<<11>>27;
    int rd=introduction<<16>>27;
    if(mode){
        strcat(outChar,"subu\t");
        char registerName[3];
        strcat(outChar,"$");
        sprintf(registerName,"%d",rd);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rs);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rt);
        strcat(outChar,registerName);
    }else{
        mips->registers[rd]=(unsigned int)mips->registers[rs]-(unsigned int)mips->registers[rt];
        int temp=mips->registers[rd];
        if(temp!=mips->registers[rd])
            changedReg=rd;
        else
            changedReg=-1;
        changedMem=-1;
        mips->pc+=4;
    }
}
void and_Intro(bool mode, unsigned int introduction, char*& outChar ,int &changedReg,int &changedMem,Computer mips){
    int rs=(introduction<<6>>27);
    int rt=introduction<<11>>27;
    int rd=introduction<<16>>27;
    if(mode){
        strcat(outChar,"and\t");
        char registerName[3];
        strcat(outChar,"$");
        sprintf(registerName,"%d",rd);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rs);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rt);
        strcat(outChar,registerName);
    }else{
        mips->registers[rd]=mips->registers[rs]&mips->registers[rt];
        int temp=mips->registers[rd];
        if(temp!=mips->registers[rd])
            changedReg=rd;
        else
            changedReg=-1;
        changedMem=-1;
        mips->pc+=4;
    }
}
void or_Intro(bool mode, unsigned int introduction, char*& outChar,int &changedReg,int &changedMem,Computer mips ){
    int rs=(introduction<<6>>27);
    int rt=introduction<<11>>27;
    int rd=introduction<<16>>27;
    if(mode){
        strcat(outChar,"or\t");
        char registerName[3];
        strcat(outChar,"$");
        sprintf(registerName,"%d",rd);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rs);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rt);
        strcat(outChar,registerName);
    }else{
        mips->registers[rd]=mips->registers[rs]|mips->registers[rt];
        int temp=mips->registers[rd];
        if(temp!=mips->registers[rd])
            changedReg=rd;
        else
            changedReg=-1;
        changedMem=-1;
        mips->pc+=4;
    }
}
void xor_Intro(bool mode, unsigned int introduction, char*& outChar ,int &changedReg,int &changedMem,Computer mips){
    int rs=(introduction<<6>>27);
    int rt=introduction<<11>>27;
    int rd=introduction<<16>>27;
    if(mode){
        strcat(outChar,"xor\t");
        char registerName[3];
        strcat(outChar,"$");
        sprintf(registerName,"%d",rd);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rs);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rt);
        strcat(outChar,registerName);
    }else{
        mips->registers[rd]=mips->registers[rs]^mips->registers[rt];
        int temp=mips->registers[rd];
        if(temp!=mips->registers[rd])
            changedReg=rd;
        else
            changedReg=-1;
        changedMem=-1;
        mips->pc+=4;
    }
}
void nor_Intro(bool mode, unsigned int introduction, char*& outChar ,int &changedReg,int &changedMem,Computer mips){

    int rs=(introduction<<6>>27);
    int rt=introduction<<11>>27;
    int rd=introduction<<16>>27;if(mode){
        strcat(outChar,"nor\t");
        char registerName[3];
        strcat(outChar,"$");
        sprintf(registerName,"%d",rd);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rs);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rt);
        strcat(outChar,registerName);
    }else{
        mips->registers[rd]=~(mips->registers[rs]|mips->registers[rt]);
        int temp=mips->registers[rd];
        if(temp!=mips->registers[rd])
            changedReg=rd;
        else
            changedReg=-1;
        changedMem=-1;
        mips->pc+=4;
    }
}
void slt_Intro(bool mode, unsigned int introduction, char*& outChar ,int &changedReg,int &changedMem,Computer mips){
    int rs=(introduction<<6>>27);
    int rt=introduction<<11>>27;
    int rd=introduction<<16>>27;
    if(mode){
        strcat(outChar,"slt\t");
        char registerName[3];
        strcat(outChar,"$");
        sprintf(registerName,"%d",rd);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rs);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rt);
        strcat(outChar,registerName);
    }else{

        if(mips->registers[rs]<mips->registers[rt])
            mips->registers[rd]=1;
        else mips->registers[rd]=0;

        int temp=mips->registers[rd];
        if(temp!=mips->registers[rd])
            changedReg=rd;
        else
            changedReg=-1;
        changedMem=-1;
        mips->pc+=4;
    }
}
void sltu_Intro(bool mode, unsigned int introduction, char*& outChar ,int &changedReg,int &changedMem,Computer mips){
    int rs=(introduction<<6>>27);
    int rt=introduction<<11>>27;
    int rd=introduction<<16>>27;
    if(mode){
        strcat(outChar,"sltu\t");


        char registerName[3];
        strcat(outChar,"$");
        sprintf(registerName,"%d",rd);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rs);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rt);
        strcat(outChar,registerName);
    }else{
        if((unsigned int)mips->registers[rs]<(unsigned int)mips->registers[rt])
            mips->registers[rd]=1;
        else mips->registers[rd]=0;

        int temp=mips->registers[rd];
        if(temp!=mips->registers[rd])
            changedReg=rd;
        else
            changedReg=-1;
        changedMem=-1;
        mips->pc+=4;
    }
}
void sll_Intro(bool mode, unsigned int introduction, char*& outChar ,int &changedReg,int &changedMem,Computer mips){
    int rt=introduction<<11>>27;
    int rd=introduction<<16>>27;
    int shamt=introduction<<21>>27;
    if(mode){
        strcat(outChar,"sll\t");
        char registerName[3];
        strcat(outChar,"$");
        sprintf(registerName,"%d",rd);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rt);
        strcat(outChar,registerName);
        strcat(outChar,", ");
        sprintf(registerName,"%d",shamt);
        strcat(outChar,registerName);
    }else{
        mips->registers[rd]=mips->registers[rt]<<shamt;
        int temp=mips->registers[rd];
        if(temp!=mips->registers[rd])
            changedReg=rd;
        else
            changedReg=-1;
        changedMem=-1;
        mips->pc+=4;
    }
}
void srl_Intro(bool mode, unsigned int introduction, char*& outChar ,
               int &changedReg,int &changedMem,Computer mips){
    int rt=introduction<<11>>27;
    int rd=introduction<<16>>27;
    int shamt=introduction<<21>>27;
    if(mode){
        strcat(outChar,"srl\t");

        char registerName[3];
        strcat(outChar,"$");
        sprintf(registerName,"%d",rd);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rt);
        strcat(outChar,registerName);
        strcat(outChar,", ");
        sprintf(registerName,"%d",shamt);
        strcat(outChar,registerName);
    }else{
        mips->registers[rd]=(unsigned int)mips->registers[rt]>>shamt;
        int temp=mips->registers[rd];
        if(temp!=mips->registers[rd])
            changedReg=rd;
        else
            changedReg=-1;
        changedMem=-1;
        mips->pc+=4;
    }
}
void sra_Intro(bool mode, unsigned int introduction, char*& outChar ,int &changedReg,int &changedMem,Computer mips){
    int rt=introduction<<11>>27;
    int rd=introduction<<16>>27;
    int shamt=introduction<<21>>27;
    if(mode){
        strcat(outChar,"sra\t");
        char registerName[3];
        strcat(outChar,"$");
        sprintf(registerName,"%d",rd);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rt);
        strcat(outChar,registerName);
        strcat(outChar,", ");
        sprintf(registerName,"%d",shamt);
        strcat(outChar,registerName);
    }else{
        mips->registers[rd]=mips->registers[rt]>>shamt;
        int temp=mips->registers[rd];
        if(temp!=mips->registers[rd])
            changedReg=rd;
        else
            changedReg=-1;
        changedMem=-1;
        mips->pc+=4;
    }
}
void sllv_Intro(bool mode, unsigned int introduction, char*& outChar ,int &changedReg,int &changedMem,Computer mips){
    int rs=(introduction<<6>>27);
    int rt=introduction<<11>>27;
    int rd=introduction<<16>>27;
    if(mode){
        strcat(outChar,"sllv\t");
        char registerName[3];
        strcat(outChar,"$");
        sprintf(registerName,"%d",rd);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rt);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rs);
        strcat(outChar,registerName);
    }else{
        mips->registers[rd]=mips->registers[rt]<<mips->registers[rs];
        int temp=mips->registers[rd];
        if(temp!=mips->registers[rd])
            changedReg=rd;
        else
            changedReg=-1;
        changedMem=-1;
        mips->pc+=4;
    }
}
void srlv_Intro(bool mode, unsigned int introduction, char*& outChar ,int &changedReg,int &changedMem,Computer mips){
    int rs=(introduction<<6>>27);
    int rt=introduction<<11>>27;
    int rd=introduction<<16>>27;
    if(mode){
        strcat(outChar,"srlv\t");


        char registerName[3];
        strcat(outChar,"$");
        sprintf(registerName,"%d",rd);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rt);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rs);
        strcat(outChar,registerName);
    }else{
        mips->registers[rd]=(unsigned int)mips->registers[rt]>>mips->registers[rs];
        int temp=mips->registers[rd];
        if(temp!=mips->registers[rd])
            changedReg=rd;
        else
            changedReg=-1;
        changedMem=-1;
        mips->pc+=4;
    }
}
void srav_Intro(bool mode, unsigned int introduction, char*& outChar ,int &changedReg,int &changedMem,Computer mips){
    int rs=(introduction<<6>>27);
    int rt=introduction<<11>>27;
    int rd=introduction<<16>>27;
    if(mode){
        strcat(outChar,"srav\t");


        char registerName[3];
        strcat(outChar,"$");
        sprintf(registerName,"%d",rd);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rt);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rs);
        strcat(outChar,registerName);
    }else{
        mips->registers[rd]=mips->registers[rt]>>mips->registers[rs];
        int temp=mips->registers[rd];
        if(temp!=mips->registers[rd])
            changedReg=rd;
        else
            changedReg=-1;
        changedMem=-1;
        mips->pc+=4;
    }
}
void jr_Intro(bool mode, unsigned int introduction, char*& outChar ,int &changedReg,int &changedMem,Computer mips){
    int rs=introduction<<6>>27;
    if(mode){
        strcat(outChar,"jr\t$");
        char registerName[3];
        sprintf(registerName,"%d",rs);
        strcat(outChar,registerName);
    }else{
        mips->pc=mips->registers[rs];
        changedReg=-1;
        changedMem=-1;
    }
}
//I-type
void addi_Intro(bool mode, unsigned int introduction, char*& outChar ,int &changedReg,int &changedMem,Computer mips){
    int rs=(introduction<<6>>27);
    int rt=introduction<<11>>27;
    int immediate=introduction<<16>>16;
    if(immediate>>15){
        immediate|=(-1>>16<<16);
    }
    if(mode){
        strcat(outChar,"addi\t");

        char registerName[3];
        char immediateName[10];
        strcat(outChar,"$");
        sprintf(registerName,"%d",rt);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rs);
        strcat(outChar,registerName);
        strcat(outChar,", ");
        sprintf(immediateName,"%d",immediate);
        strcat(outChar,immediateName);
    }else{
        mips->registers[rt]=mips->registers[rs]+immediate;
        int temp=mips->registers[rt];
        if(temp!=mips->registers[rt])
            changedReg=rt;
        else
            changedReg=-1;
        changedMem=-1;
        mips->pc+=4;
    }
}
void addiu_Intro(bool mode, unsigned int introduction, char*& outChar ,int &changedReg,int &changedMem,Computer mips){
    int rs=(introduction<<6>>27);
    int rt=introduction<<11>>27;
    int immediate=introduction<<16>>16;
    if(immediate>>15){
        immediate|=(-1>>16<<16);
    }
    if(mode){
        strcat(outChar,"addiu\t");
        char registerName[3];
        char immediateName[10];
        strcat(outChar,"$");
        sprintf(registerName,"%d",rt);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rs);
        strcat(outChar,registerName);
        strcat(outChar,", ");
        sprintf(immediateName,"%d",immediate);
        strcat(outChar,immediateName);
    }else{
        mips->registers[rt]=(unsigned int)mips->registers[rs]+(unsigned int)immediate;
        int temp=mips->registers[rt];
        if(temp!=mips->registers[rt])
            changedReg=rt;
        else
            changedReg=-1;
        changedMem=-1;
        mips->pc+=4;
    }
}
void andi_Intro(bool mode, unsigned int introduction, char*& outChar ,int &changedReg,int &changedMem,Computer mips){
    int rs=(introduction<<6>>27);
    int rt=introduction<<11>>27;
    int immediate=introduction<<16>>16;

    if(mode){
        strcat(outChar,"andi\t");
//    if(immediate>>15){
//        immediate|=(-1>>16<<16);
//    }
        char registerName[3];
        char immediateName[10];
        strcat(outChar,"$");
        sprintf(registerName,"%d",rt);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rs);
        strcat(outChar,registerName);
        strcat(outChar,", 0x");
        sprintf(immediateName,"%x",immediate);
        strcat(outChar,immediateName);
    }else{
        mips->registers[rt]=mips->registers[rs]&immediate;
        int temp=mips->registers[rt];
        if(temp!=mips->registers[rt])
            changedReg=rt;
        else
            changedReg=-1;
        changedMem=-1;
        mips->pc+=4;
    }
}
void ori_Intro(bool mode, unsigned int introduction, char*& outChar ,int &changedReg,int &changedMem,Computer mips){
    int rs=(introduction<<6>>27);
    int rt=introduction<<11>>27;
    int immediate=introduction<<16>>16;

    if(mode){
        strcat(outChar,"ori\t");
//            if(immediate>>15){
//        immediate|=(-1>>16<<16);
//    }
        char registerName[3];
        char immediateName[10];
        strcat(outChar,"$");
        sprintf(registerName,"%d",rt);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rs);
        strcat(outChar,registerName);
        strcat(outChar,", 0x");
        sprintf(immediateName,"%x",immediate);
        strcat(outChar,immediateName);
    }else{
        mips->registers[rt]=mips->registers[rs]|immediate;
        int temp=mips->registers[rt];
        if(temp!=mips->registers[rt])
            changedReg=rt;
        else
            changedReg=-1;
        changedMem=-1;
        mips->pc+=4;
    }
}
void xori_Intro(bool mode, unsigned int introduction, char*& outChar ,int &changedReg,int &changedMem,Computer mips){
    int rs=(introduction<<6>>27);
    int rt=introduction<<11>>27;
    int immediate=introduction<<16>>16;

    if(mode){
        strcat(outChar,"xori\t");
//    if(immediate>>15){
//        immediate|=(-1>>16<<16);
//    }

        char registerName[3];
        char immediateName[10];
        strcat(outChar,"$");
        sprintf(registerName,"%d",rt);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rs);
        strcat(outChar,registerName);
        strcat(outChar,", ");
        sprintf(immediateName,"%d",immediate);
        strcat(outChar,immediateName);
    }else{
        mips->registers[rt]=mips->registers[rs]^immediate;
        int temp=mips->registers[rt];
        if(temp!=mips->registers[rt])
            changedReg=rt;
        else
            changedReg=-1;
        changedMem=-1;
        mips->pc+=4;
    }
}
void lui_Intro(bool mode, unsigned int introduction, char*& outChar,int &changedReg,int &changedMem,Computer mips ){
    int rt=introduction<<11>>27;
    int immediate=introduction<<16>>16;

    if(mode){
        strcat(outChar,"lui\t");
//        if(immediate>>15){
//            immediate|=(-1>>16<<16);
//        }
        char registerName[4];
        char immediateName[10];
        strcat(outChar,"$");
        sprintf(registerName,"%d",rt);
        strcat(outChar,registerName);
        strcat(outChar,", 0x");
        sprintf(immediateName,"%x",immediate);
        strcat(outChar,immediateName);
    }else{
        mips->registers[rt]=0;
        mips->registers[rt]|=immediate<<16;
        int temp=mips->registers[rt];
        if(temp!=mips->registers[rt])
            changedReg=rt;
        else
            changedReg=-1;
        changedMem=-1;
        mips->pc+=4;
    }
}
//TODO
void lw_Intro(bool mode, unsigned int introduction, char*& outChar ,int &changedReg,int &changedMem,Computer mips){
    int rs=(introduction<<6>>27);
    int rt=introduction<<11>>27;
    int immediate=introduction<<16>>16;
    if(immediate>>15){
        immediate|=(-1>>16<<16);
    }
    if(mode){
        strcat(outChar,"lw\t");


        char registerName[3];
        char immediateName[10];
        strcat(outChar,"$");
        sprintf(registerName,"%d",rt);
        strcat(outChar,registerName);
        strcat(outChar,", ");
        sprintf(immediateName,"%d",immediate);
        strcat(outChar,immediateName);

        strcat(outChar,"($");
        sprintf(registerName,"%d",rs);
        strcat(outChar,registerName);
        strcat(outChar,")");

    }else{
        mips->registers[rt]=contents(mips,mips->registers[rs]+immediate);
        int temp=mips->registers[rt];
        if(temp!=mips->registers[rt])
            changedReg=rt;
        else
            changedReg=-1;
        changedMem=-1;
        mips->pc+=4;
    }
}
void sw_Intro(bool mode, unsigned int introduction, char*& outChar ,int &changedReg,int &changedMem,Computer mips){
    int rs=(introduction<<6>>27);
    int rt=introduction<<11>>27;
    int immediate=introduction<<16>>16;
    if(immediate>>15){
        immediate|=(-1>>16<<16);
    }
    if(mode){
        strcat(outChar,"sw\t");


        char registerName[3];
        char immediateName[10];
        strcat(outChar,"$");
        sprintf(registerName,"%d",rt);
        strcat(outChar,registerName);
        strcat(outChar,", ");
        sprintf(immediateName,"%d",immediate);
        strcat(outChar,immediateName);

        strcat(outChar,"($");
        sprintf(registerName,"%d",rs);
        strcat(outChar,registerName);
        strcat(outChar,")");
    }else{
        int index = (mips->registers[rs]+immediate-0x00400000)/4;
        if ((((mips->registers[rs]+immediate) & 0x3) != 0) || (index < 0) || (index >= (MAXNUMINSTRS+MAXNUMDATA))) {
            printf("Invalid Address: %8.8x", mips->registers[rs]);
            exit(0);
        }
        mips->memory[index]=mips->registers[rt];
        changedReg=-1;
        changedMem=mips->registers[rs]+immediate;
        mips->pc+=4;
    }
}
void beq_Intro(bool mode, unsigned int introduction, char*& outChar , unsigned int pc,int &changedReg,int &changedMem,Computer mips){
    int rs=(introduction<<6>>27);
    int rt=introduction<<11>>27;
    int immediate=introduction<<16>>16;
    if(immediate>>15){
        immediate|=(-1>>16<<16);
    }
    if(mode){
        strcat(outChar,"beq\t");


        char registerName[3];
        char immediateName[10];
        strcat(outChar,"$");
        sprintf(registerName,"%d",rs);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rt);
        strcat(outChar,registerName);
        strcat(outChar,", 0x");
        sprintf(immediateName,"%8.8x",immediate*4+4+pc);
        strcat(outChar,immediateName);
    }else{
        if(mips->registers[rs]==mips->registers[rt])
            mips->pc=mips->pc+4+4*immediate;
        else mips->pc+=4;
        changedReg=-1;
        changedMem=-1;
    }
}
void bne_Intro(bool mode, unsigned int introduction, char*& outChar , unsigned int pc,int &changedReg,int &changedMem,Computer mips){
    int rs=(introduction<<6>>27);
    int rt=introduction<<11>>27;
    int immediate=introduction<<16>>16;
    if(immediate>>15){
        immediate|=(-1>>16<<16);
    }
    if(mode){
        strcat(outChar,"bne\t");


        char registerName[3];
        char immediateName[10];
        strcat(outChar,"$");
        sprintf(registerName,"%d",rs);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rt);
        strcat(outChar,registerName);
        strcat(outChar,", 0x");
        sprintf(immediateName,"%8.8x",immediate*4+4+pc);
        strcat(outChar,immediateName);
    }else{
        if(mips->registers[rs]!=mips->registers[rt])
            mips->pc=mips->pc+4+4*immediate;
        else mips->pc+=4;
        changedReg=-1;
        changedMem=-1;
    }
}
void slti_Intro(bool mode, unsigned int introduction, char*& outChar ,int &changedReg,int &changedMem,Computer mips){
    int rs=(introduction<<6>>27);
    int rt=introduction<<11>>27;
    int immediate=introduction<<16>>16;
    if(immediate>>15){
        immediate|=(-1>>16<<16);
    }
    if(mode){
        strcat(outChar,"slti\t");


        char registerName[3];
        char immediateName[10];
        strcat(outChar,"$");
        sprintf(registerName,"%d",rt);
        strcat(outChar,registerName);
        strcat(outChar,", $");
        sprintf(registerName,"%d",rs);
        strcat(outChar,registerName);
        strcat(outChar,", ");
        sprintf(immediateName,"%d",immediate);
        strcat(outChar,immediateName);
    }else{
        if(mips->registers[rs]<immediate)
            mips->registers[rt]=1;
        else
            mips->registers[rt]=0;
        int temp=mips->registers[rt];
        if(temp!=mips->registers[rt])
            changedReg=rt;
        else
            changedReg=-1;
        changedMem=-1;
        mips->pc+=4;
    }
}
void sltiu_Intro(bool mode, unsigned int introduction, char*& outChar ,int &changedReg,int &changedMem,Computer mips){
    int rs=(introduction<<6>>27);
    int rt=introduction<<11>>27;
    int immediate=introduction<<16>>16;
    if(immediate>>15){
        immediate|=(-1>>16<<16);
    }
    if(mode){
        strcat(outChar,"sltiu\t");


        char registerName[3];
        char immediateName[10];
        strcat(outChar,"$");
        sprintf(registerName,"%d",rt);
        strcat(outChar,registerName);
        strcat(outChar,", $");int temp=mips->registers[rt];
        if(temp!=mips->registers[rt])
            changedReg=rt;
        else
            changedReg=-1;
        sprintf(registerName,"%d",rs);
        strcat(outChar,registerName);
        strcat(outChar,", ");
        sprintf(immediateName,"%d",immediate);
        strcat(outChar,immediateName);
    }else{
        if((unsigned int)mips->registers[rs]<(unsigned int)immediate)
            mips->registers[rt]=1;
        else
            mips->registers[rt]=0;
        int temp=mips->registers[rt];
        if(temp!=mips->registers[rt])
            changedReg=rt;
        else
            changedReg=-1;
        changedMem=-1;
        mips->pc+=4;
    }
}
//J-type
void j_Intro(bool mode, unsigned int introduction, char*& outChar ,int &changedReg,int &changedMem,Computer mips){
    int address=introduction<<6>>4;
    if(mode){
        strcat(outChar,"j\t0x");

        char addressChar[9];
        sprintf(addressChar,"%8.8x",address);
        strcat(outChar,addressChar);
    }else{
        mips->pc=address;
        changedReg=-1;
        changedMem=-1;
    }
}
void jal_Intro(bool mode, unsigned int introduction, char*& outChar ,int &changedReg,int &changedMem,Computer mips){
    int address=introduction<<6>>4;
    if(mode){
        strcat(outChar,"jal\t0x");

        char addressChar[9];
        sprintf(addressChar,"%8.8x",address);
        strcat(outChar,addressChar);
    }else{
        mips->registers[31]=mips->pc+4;
        mips->pc=address;
        changedReg=31;
        changedMem=-1;
    }
}
char* r_Introduction(unsigned int introduction,int &changedReg,int &changedMem,bool mode,Computer mips){
    int func=introduction<<26>>26;
    char* outChar=new char[20];
    for(int i=0;i<20;i++){
        outChar[i]='\0';
    }
    if(func==32)
        add_Intro(mode,introduction,outChar,changedReg,changedMem,mips);
    else if(func==33)
        addu_Intro(mode,introduction,outChar,changedReg,changedMem,mips);
    else if(func==34)
        sub_Intro(mode,introduction,outChar,changedReg,changedMem,mips);
    else if(func==35)
        subu_Intro(mode,introduction,outChar,changedReg,changedMem,mips);
    else if(func==36)
        and_Intro(mode,introduction,outChar,changedReg,changedMem,mips);
    else if(func==37)
        or_Intro(mode,introduction,outChar,changedReg,changedMem,mips);
    else if(func==38)
        xor_Intro(mode,introduction,outChar,changedReg,changedMem,mips);
    else if(func==39)
        nor_Intro(mode,introduction,outChar,changedReg,changedMem,mips);
        ////////////////
    else if(func==42)
        slt_Intro(mode,introduction,outChar,changedReg,changedMem,mips);
    else if(func==43)
        sltu_Intro(mode,introduction,outChar,changedReg,changedMem,mips);
        ////////////////
    else if(func==0)
        sll_Intro(mode,introduction,outChar,changedReg,changedMem,mips);
    else if(func==2)
        srl_Intro(mode,introduction,outChar,changedReg,changedMem,mips);
    else if(func==3)
        sra_Intro(mode,introduction,outChar,changedReg,changedMem,mips);
    else if(func==4)
        sllv_Intro(mode,introduction,outChar,changedReg,changedMem,mips);
    else if(func==6)
        srlv_Intro(mode,introduction,outChar,changedReg,changedMem,mips);
    else if(func==7)
        srav_Intro(mode,introduction,outChar,changedReg,changedMem,mips);
    else if(func==8)
        jr_Intro(mode,introduction,outChar,changedReg,changedMem,mips);
    return outChar;
}

char* i_Introduction(unsigned int instr, unsigned int pc,int &changedReg,int &changedMem,bool mode,Computer mips){
    int opcode=instr>>26;
    char* outChar=new char[20];
    for(int i=0;i<20;i++){
        outChar[i]='\0';
    }
    if(opcode==8) addi_Intro(mode,instr,outChar,changedReg,changedMem,mips);
    else if(opcode==9) addiu_Intro(mode,instr,outChar,changedReg,changedMem,mips);
    else if(opcode==12) andi_Intro(mode,instr,outChar,changedReg,changedMem,mips);
    else if(opcode==13) ori_Intro(mode,instr,outChar,changedReg,changedMem,mips);
    else if(opcode==14) xori_Intro(mode,instr,outChar,changedReg,changedMem,mips);
    else if(opcode==15) lui_Intro(mode,instr,outChar,changedReg,changedMem,mips);
    else if(opcode==35) lw_Intro(mode,instr,outChar,changedReg,changedMem,mips);
    else if(opcode==43) sw_Intro(mode,instr,outChar,changedReg,changedMem,mips);
    else if(opcode==4) beq_Intro(mode,instr,outChar,pc,changedReg,changedMem,mips);
    else if(opcode==5) bne_Intro(mode,instr,outChar,pc,changedReg,changedMem,mips);
    else if(opcode==10) slti_Intro(mode,instr,outChar,changedReg,changedMem,mips);
    else if(opcode==11) sltiu_Intro(mode,instr,outChar,changedReg,changedMem,mips);
    return outChar;
}
char* j_Instroduction(unsigned int instr,int &changedReg,int &changedMem,bool mode,Computer mips){
    int opcode=instr>>26;
    char* outChar=new char[20];
    for(int i=0;i<20;i++){
        outChar[i]='\0';
    }
    if(opcode==2) j_Intro(mode,instr,outChar,changedReg,changedMem,mips);
    else if(opcode==3) jal_Intro(mode,instr,outChar,changedReg,changedMem,mips);
    return outChar;
}
/*
 *  Return a string containing the disassembled version of the given
 *  instruction.  You absolutely MUST follow the formatting instructions
 *  given in the assignment.  Note that the string your return should
 *  not include a tab at the beginning or a newline at the end since
 *  those are added in computer.c where this function is called.
 *
 *  Finally you are responsible for managing the memory associated with
 *  any string you return.  If you use malloc, you will somehow need to
 *  free the memory later (note that you cannot modify computer.c).
 *  Hint: static or global variables.
 */
char * disassembled (unsigned int instr, unsigned int pc) {
    /* You replace this code by the right stuff. */
	//if (/*instruction isn't supported */) exit (0); // Your program must exit when an unsupported instruction is detected
    if(instr==0||pc>0x00400000+1024*4) exit(0);
    int opcode=instr>>26;
    int changedReg=-1,changedMem=-1;
    if(opcode==0)
        return r_Introduction(instr,changedReg,changedMem, true,NULL);
    else if(opcode==2||opcode==3)
        return j_Instroduction(instr,changedReg,changedMem, true,NULL);
    else
        return i_Introduction(instr,pc,changedReg,changedMem, true,NULL);


    //return "";
}

/*
 *  Simulate the execution of the given instruction, updating the
 *  pc appropriately.
 *
 *  If the instruction modified a register--i.e. if it was lw,
 *  addu, addiu, subu, sll, srl, and, andi, or, ori, lui, or slt
 *  to list a few examples-- return the index of the modified
 *  register in *changedReg, otherwise return -1 in *changedReg.
 *  Note that you should never return 0 in *changedReg, since
 *  $0 cannot be changed!  Note that even if the instruction
 *  changes the register back to it's old value
 *  (e.g. addu $3, $3, $0) the destination register ($3 in the
 *  example) should be marked changed!
 *
 *  If the instruction was sw, return the address of the
 *  updated memory location in *changedMem, otherwise return -1
 *  in *changedMem.
 */
void simulateInstr (Computer mips, unsigned int instr, int *changedReg, int *changedMem) {
    /* You replace this code by the right stuff. */
    if(instr==0) exit(0);
    int opcode=instr>>26;
    *changedReg = -1;
    *changedMem = -1;
    if(opcode==0)
        r_Introduction(instr,*changedReg,*changedMem, false,mips);
    else if(opcode==2||opcode==3)
        j_Instroduction(instr,*changedReg,*changedMem,false,mips);
    else
        i_Introduction(instr,mips->pc,*changedReg,*changedMem, false,mips);
    //mips->pc = mips->pc + 4;
//    *changedReg = -1;
//    *changedMem = -1;
}
