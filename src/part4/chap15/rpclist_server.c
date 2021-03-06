/* rpclist_server.c
 *
 * Copyright (c) 2000 Sean Walton and Macmillan Publishers.  Use may be in
 * whole or in part in accordance to the General Public License (GPL).
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
*/

/*****************************************************************************/
/*** rpclist_server.c                                                      ***/
/***                                                                       ***/
/*****************************************************************************/

/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "rpclist.h"

NodeUnion *
getlist_1_svc(char **argp, struct svc_req *rqstp)
{	int i;
	char TempS[1000];
	static NodeUnion  result;
	TNode list;

	xdr_free((xdrproc_t)xdr_NodeUnion, (void*)&result);

	list = result.NodeUnion_u.NameList = calloc(1, sizeof(TNode*));

	for ( i = 0; i < 20; i++ )
	{
		sprintf(TempS, "This is test #%d", i+1);
		list->Name = strdup(TempS);
		if ( i < 19 )
		{
			list->Next = calloc(1, sizeof(TNode*));
			list = list->Next;
		}
	}

	result.Err = 0;

	return &result;
}
