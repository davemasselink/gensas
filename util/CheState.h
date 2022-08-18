//
// Copyright (C) 2022, UChicago Argonne, LLC. All rights reserved.
//
// Software Name: Generic Semi-Analytical Simulation Tool (GenSAS)
// By: Argonne National Laboratory
// OPEN SOURCE LICENSE
// 
// Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
// 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
// 
// 
// ******************************************************************************************************
// DISCLAIMER
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
// WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
// PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY 
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// ***************************************************************************************************
// 
#ifndef _Che_State_H_
#define _Che_State_H_

#include "CheDataFormat.h"
#include "SafeArmadillo.h"

using namespace arma;
using namespace che::io;

namespace che {
	namespace util {

		class CheStateIdx {
		public:
			int nState;
			//Network - voltage and reactive power
			uvec vrIdx;
			uvec viIdx;
			uvec qIdx; //reactive power generated by PV/SW buses
			uvec pIdx; //active power generated by SW buses
			//induction motor
			uvec sIdx; 
			uvec indEr1Idx; //Order-3
			uvec indEm1Idx; //Order-3
			uvec indEr2Idx; //Order-5
			uvec indEm2Idx; //Order-5
			//syn
			uvec mDeltaIdx;
			uvec mOmegaIdx;
			uvec mEq1Idx;
			uvec mEq2Idx;
			uvec mEd1Idx;
			uvec mEd2Idx;
			uvec mPsidIdx;
			uvec mPsiqIdx;
			uvec mPgIdx;
			uvec mEfIdx;
			//exc1
			uvec avr1mIdx;
			uvec avr1r1Idx;
			uvec avr1r2Idx;
			uvec avr1rIdx;
			uvec avr1fIdx;
			//exc2
			uvec avr2mIdx;
			uvec avr2r1Idx;
			uvec avr2rIdx;
			uvec avr2r2Idx;
			uvec avr2fIdx;
			//exc3
			uvec avrmIdx;
			uvec avrrIdx;
			uvec avrfIdx;
			uvec avrrefIdx;
			//tg1
			uvec tg1inIndx;
			uvec tg11Idx;
			uvec tg12Idx;
			uvec tg13Idx;
			//tg2
			uvec tg2gIdx;
			uvec tg2mIdx;
			//common tg
			uvec tmechIdx;
			//AGC and AVC
			uvec fIdx;
			uvec qpltIdx;
			uvec vgIdx;

			CheStateIdx();

			CheStateIdx(const CheStateIdx& s);

			CheStateIdx& operator=(const CheStateIdx&) = default;
		};

		class CheState {
		public:
			vec state;
			CheStateIdx stateIdx;

			CheState();

			CheState(int nState);

			CheState(const CheState & st);

			CheState(const chedata::PsatDataSet &psat);

			CheState(const chedata::PsatDataSet &psat, const vec & state);

			vec getSubVec(uvec idx) const;

			void setSubVec(uvec idx, vec value);
		};
	}
}
#endif