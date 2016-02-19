//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for full license information.
//
// DataReader.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Basics.h"

#define DATAREADER_EXPORTS
#include "DataReader.h"
#include "Config.h"
#include "ReaderShim.h"
#include "HTKMLFReader.h"
#include "HeapMemoryProvider.h"

namespace Microsoft { namespace MSR { namespace CNTK {

    auto factory = [](const ConfigParameters& parameters) -> ReaderPtr
    {
        return std::make_shared<HTKMLFReader>(std::make_shared<HeapMemoryProvider>(), parameters);
    };

    extern "C" DATAREADER_API void GetReaderF(IDataReader<float>** preader)
    {
        *preader = new ReaderShim<float>(factory);
    }

    extern "C" DATAREADER_API void GetReaderD(IDataReader<double>** preader)
    {
        *preader = new ReaderShim<double>(factory);
    }

} } }
