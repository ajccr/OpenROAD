///////////////////////////////////////////////////////////////////////////////
// BSD 3-Clause License
//
// Copyright (c) 2019, Nefelus Inc
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// * Neither the name of the copyright holder nor the names of its
//   contributors may be used to endorse or promote products derived from
//   this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#pragma once

#include "dbCore.h"
#include "dbVector.h"
#include "odb/dbId.h"
#include "odb/odb.h"

namespace odb {

class _dbMTerm;
class _dbBox;
class _dbPolygon;
class _dbDatabase;
class dbIStream;
class dbOStream;
class _dbAccessPoint;

class _dbMPin : public _dbObject
{
 public:
  // PERSISTANT-MEMBERS
  dbId<_dbMTerm> _mterm;
  dbId<_dbBox> _geoms;
  dbId<_dbPolygon> _poly_geoms;
  dbId<_dbMPin> _next_mpin;
  dbVector<dbVector<dbId<_dbAccessPoint>>>
      aps_;  // A vector of access points for each unique instance(master,
             // orient, origin relevant to track). The outer index is the
             // pin-access/unique-instance idx.

  _dbMPin(_dbDatabase*, const _dbMPin& p);
  _dbMPin(_dbDatabase*);
  ~_dbMPin();

  bool operator==(const _dbMPin& rhs) const;
  bool operator!=(const _dbMPin& rhs) const { return !operator==(rhs); }
  void collectMemInfo(MemInfo& info);
  void addAccessPoint(uint idx, _dbAccessPoint* ap);
};

dbOStream& operator<<(dbOStream& stream, const _dbMPin& mpin);
dbIStream& operator>>(dbIStream& stream, _dbMPin& mpin);

}  // namespace odb
