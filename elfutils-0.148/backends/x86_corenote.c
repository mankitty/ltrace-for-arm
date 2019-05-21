/* x86-specific core note handling, pieces common to x86-64 and i386.
   Copyright (C) 2005-2010 Red Hat, Inc.
   This file is part of Red Hat elfutils.

   Red Hat elfutils is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by the
   Free Software Foundation; version 2 of the License.

   Red Hat elfutils is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License along
   with Red Hat elfutils; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301 USA.

   Red Hat elfutils is an included package of the Open Invention Network.
   An included package of the Open Invention Network is a package for which
   Open Invention Network licensees cross-license their patents.  No patent
   license is granted, either expressly or impliedly, by designation as an
   included package.  Should you wish to participate in the Open Invention
   Network licensing program, please visit www.openinventionnetwork.com
   <http://www.openinventionnetwork.com>.  */

#define	EXTRA_NOTES_IOPERM \
  case NT_386_IOPERM: \
    return ioperm_info (nhdr->n_descsz, \
			regs_offset, nregloc, reglocs, nitems, items);

static int
ioperm_info (GElf_Word descsz, GElf_Word *regs_offset,
	     size_t *nregloc, const Ebl_Register_Location **reglocs,
	     size_t *nitems, const Ebl_Core_Item **items)
{
  static const Ebl_Core_Item ioperm_item =
    { .type = ELF_T_WORD, .format = 'b', .name = "ioperm" };

  if (descsz % 4 != 0)
    return 0;

  *regs_offset = 0;
  *nregloc = 0;
  *reglocs = NULL;
  *nitems = 1;
  *items = &ioperm_item;
  return 1;
}
