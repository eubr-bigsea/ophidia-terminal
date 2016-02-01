/*
    Ophidia Terminal
    Copyright (C) 2012-2016 CMCC Foundation

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef OPH_TERM_CLIENT_H_
#define OPH_TERM_CLIENT_H_

#include "../env/hashtbl.h"
#include "../env/oph_term_env.h"

#define OPH_TERM_WORKFLOW_DELIMITER "?"
#define OPH_TERM_MARKER_DELIMITER "#"

#define WORKFLOW_MAX_LEN 100*1024

#define WRAPPING_WORKFLOW1 "{\n  \"name\":\"%s\",\n  \"author\":\"%s\",\n  \"abstract\":\"Workflow generated by Oph_Term to wrap a command\","
#define WRAPPING_WORKFLOW2 "\n  \"sessionid\":\""
#define WRAPPING_WORKFLOW2_1 "\","
#define WRAPPING_WORKFLOW3 "\n  \"exec_mode\":\""
#define WRAPPING_WORKFLOW3_1 "\","
#define WRAPPING_WORKFLOW4 "\n  \"callback_url\":\""
#define WRAPPING_WORKFLOW4_1 "\","
#define WRAPPING_WORKFLOW4b "\n  \"command\":\""
#define WRAPPING_WORKFLOW4b_1 "\","
#define WRAPPING_WORKFLOW4c "\n  \"ncores\":\""
#define WRAPPING_WORKFLOW4c_1 "\","
#define WRAPPING_WORKFLOW4d "\n  \"cwd\":\""
#define WRAPPING_WORKFLOW4d_1 "\","
#define WRAPPING_WORKFLOW4e "\n  \"cube\":\""
#define WRAPPING_WORKFLOW4e_1 "\","
#define WRAPPING_WORKFLOW5 "\n  \"tasks\": [\n    {\n      \"name\":\"Task 0\",\n      \"operator\":\""
#define WRAPPING_WORKFLOW5_1 "\",\n      \"arguments\": ["
#define WRAPPING_WORKFLOW6 "\"%s\""
#define WRAPPING_WORKFLOW7 ",\"%s\""
#define WRAPPING_WORKFLOW8 "]\n    }\n  ]\n}"


// - cmd_line is the command typed by the user (can be NULL)
// - command is the query that will be forwarded to the server,
// so it must contain all parameters, operator- and server-related
// with the format param=value;
// - newsession is the session id returned by the server; it must be deallocated once used to set OPH_SESSION_ID
// - newdatacube is the output datacube returned by the server; it must be deallocated once used to set OPH_DATACUBE
// - newcwd is the cwd returned by the server; it must be deallocated once used to set OPH_CWD
// - user,password,host,port are login parameters
// - workflow_wrap 1 for wrapping a command in a 1-task workflow, 0 for taking query as is
// - hashtbl current environment
int oph_term_client(char *cmd_line,char *command,char **newsession,char *user,char *password,char *host,char *port, int *return_value, char **out_response, char **out_response_for_viewer, int workflow_wrap, HASHTBL *hashtbl);

#endif