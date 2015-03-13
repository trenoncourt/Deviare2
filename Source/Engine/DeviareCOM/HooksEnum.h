/*
 * Copyright (C) 2010-2015 Nektra S.A., Buenos Aires, Argentina.
 * All rights reserved. Contact: http://www.nektra.com
 *
 *
 * This file is part of Deviare
 *
 *
 * Commercial License Usage
 * ------------------------
 * Licensees holding valid commercial Deviare licenses may use this file
 * in accordance with the commercial license agreement provided with the
 * Software or, alternatively, in accordance with the terms contained in
 * a written agreement between you and Nektra.  For licensing terms and
 * conditions see http://www.nektra.com/licensing/. Use the contact form
 * at http://www.nektra.com/contact/ for further information.
 *
 *
 * GNU General Public License Usage
 * --------------------------------
 * Alternatively, this file may be used under the terms of the GNU General
 * Public License version 3.0 as published by the Free Software Foundation
 * and appearing in the file LICENSE.GPL included in the packaging of this
 * file.  Please visit http://www.gnu.org/copyleft/gpl.html and review the
 * information to ensure the GNU General Public License version 3.0
 * requirements will be met.
 *
 **/

#pragma once

#include "ObjectBase.h"

//-----------------------------------------------------------
// CNktHooksEnumImpl

class ATL_NO_VTABLE CNktHooksEnumImpl : public CComObjectRootEx<CComMultiThreadModel>,
                                        public CComCoClass<CNktHooksEnumImpl, &CLSID_NktHooksEnum>,
                                        public CNktMemMgrObj,
                                        public IObjectSafetyImpl<CNktHooksEnumImpl,
                                                                 INTERFACESAFE_FOR_UNTRUSTED_CALLER>,
                                        public CNktObjectBaseImpl<CNktHooksEnumImpl, INktHooksEnum,
                                                   CNktDvHooksEnumerator, &CLSID_NktHooksEnum,
                                                   &IID_INktHooksEnum, &LIBID_Deviare2>,
                                        public IInterfaceItemImpl<CNktHooksEnumImpl>,
                                        public INktDvEngBaseComLink
{
public:
  CNktHooksEnumImpl(__in CNktDvHooksEnumerator *lpIntObj) : CComObjectRootEx<CComMultiThreadModel>(),
                        CComCoClass<CNktHooksEnumImpl, &CLSID_NktHooksEnum>(),
                        CNktMemMgrObj(),
                        IObjectSafetyImpl<CNktHooksEnumImpl, INTERFACESAFE_FOR_UNTRUSTED_CALLER>(),
                        CNktObjectBaseImpl<CNktHooksEnumImpl, INktHooksEnum, CNktDvHooksEnumerator,
                                           &CLSID_NktHooksEnum, &IID_INktHooksEnum,
                                           &LIBID_Deviare2>(lpIntObj),
                        IInterfaceItemImpl<CNktHooksEnumImpl>(),
                        INktDvEngBaseComLink()
    {
    return;
    };

  DECLARE_REGISTRY_RESOURCEID_EX(IDR_INTERFACEREGISTRAR, L"DeviareCOM.NktHooksEnum",
                                 L"1", L"NktHooksEnum Class", CLSID_NktHooksEnum,
                                 LIBID_Deviare2, L"Neutral")

  BEGIN_COM_MAP(CNktHooksEnumImpl)
    COM_INTERFACE_ENTRY(INktHooksEnum)
    COM_INTERFACE_ENTRY(INktObject)
    COM_INTERFACE_ENTRY(IDispatch)
    COM_INTERFACE_ENTRY(IObjectSafety)
    COM_INTERFACE_ENTRY(IInterfaceItem)
    COM_INTERFACE_ENTRY(INktDvEngBaseComLink)
    COM_INTERFACE_ENTRY_AGGREGATE(IID_IMarshal, cUnkMarshaler.p)
  END_COM_MAP()

  DECLARE_PROTECT_FINAL_CONSTRUCT()

  DECLARE_GET_CONTROLLING_UNKNOWN()

  OBJBASE_DECLARE_APIS_1(CNktHooksEnumImpl,CNktDvHooksEnumerator)

public:
  STDMETHODIMP get_Count(__deref_out LONG *pVal);

  STDMETHODIMP GetAt(__in LONG index, __deref_out INktHook **ppHook);

  STDMETHODIMP First(__deref_out INktHook **ppHook);

  STDMETHODIMP Last(__deref_out INktHook **ppHook);

  STDMETHODIMP Next(__deref_out INktHook **ppHook);

  STDMETHODIMP Previous(__deref_out INktHook **ppHook);

  STDMETHODIMP GetByDeviareId(__in my_ssize_t devId, __deref_out INktHook **ppHook);

  STDMETHODIMP GetById(__in my_ssize_t _id, __deref_out INktHook **ppHook);

  STDMETHODIMP Add(__in INktHook *pHook);

  STDMETHODIMP Attach(__in VARIANT procOrId, __in VARIANT_BOOL sync);

  STDMETHODIMP Detach(__in VARIANT procOrId, __in VARIANT_BOOL sync);

  STDMETHODIMP Enable(__in VARIANT procOrId, __in VARIANT_BOOL enable, __in VARIANT_BOOL sync);

  STDMETHODIMP Hook(__in VARIANT_BOOL sync);

  STDMETHODIMP Unhook(__in VARIANT_BOOL sync);

  STDMETHODIMP QueryOverwrite(__in VARIANT procOrId, __out VARIANT *pVal);

  STDMETHODIMP get__NewEnum(__deref_out IUnknown** ppUnk);

private:
  CComPtr<IUnknown> cUnkMarshaler;
};

OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO(__uuidof(NktHooksEnum), CNktHooksEnumImpl)
