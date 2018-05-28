/*******************************************************************
    Copyright (C) 2009 FreakLabs
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:

    1. Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
    3. Neither the name of the the copyright holder nor the names of its contributors
       may be used to endorse or promote products derived from this software
       without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS'' AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
    OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
    HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
    LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
    OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
    SUCH DAMAGE.

    Originally written by Christopher Wang aka Akiba.
    Please post support questions to the FreakLabs forum.
//--------------------------------------------------------------------------------
//! \file    Cmd.h
//! \brief   Simple Command Line Interface for Arduino
//! \brief   Modified to support multiple command prompts
//! \date    2018-March
//! \author  My-Lab-odyssey
//! \version 0.7.0
//--------------------------------------------------------------------------------

*******************************************************************/
/*!
    \file
    \ingroup


*/
/**************************************************************************/
#ifndef CMD_H
#define CMD_H

#define MAX_MSG_SIZE    30
#define MAX_CMD_SIZE    10
#include <stdint.h>

// command line structure
typedef struct _cmd_t
{
    char *cmd;
    void (*func)(uint8_t argc, char **argv);
    struct _cmd_t *next;
} cmd_t;

void cmdInit();
void cmdInit(uint32_t speed);
void cmd_display();
void set_cmd_display(const char *myCMD);
void set_local_echo(boolean _fECHO);
void cmdPoll();
void cmdAdd(const char *name, void (*func)(uint8_t argc, char **argv));
uint32_t cmdStr2Num(char *str, uint8_t base);



#endif //CMD_H
