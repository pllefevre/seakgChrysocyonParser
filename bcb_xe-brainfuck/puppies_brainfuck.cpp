﻿//---------------------------------------------------------------------------

#include <vector.h>
#include <vcl.h>
#include <conio.h>
#pragma hdrstop

#include "puppies_brainfuck.h"

namespace brainfuck
{
  core::core()
  {
    m_nPos = 0;
    m_vSlots.clear();
    int n = 0;
    m_vSlots.push_back(n);
    Debug = false;
  };

  void core::next()
  {
    m_nPos++;

    if(m_nPos > m_vSlots.size() - 1 )
    {
      int n = 0;
      m_vSlots.push_back(n);
    };
  };

  void core::prev()
  {
    if(m_nPos > 0)
      m_nPos--;
  };

  void core::inc()
  {
    m_vSlots[m_nPos]++;
  };

  void core::decr()
  {
    m_vSlots[m_nPos]--;
  };

  int core::get()
  {
    return m_vSlots[m_nPos];
  };

  void core::set(int ch)
  {
    m_vSlots[m_nPos] = ch;
  };

  void core::print_state()
  {
    if(Debug)
    {
      std::wcout << L" #### core state #### \r\n";
      for(unsigned int i = 0; i < m_vSlots.size(); i++)
      {
        int ch = m_vSlots[i];
        std::wcout << L"slot " << i << L": int(" << ch << "), wchar_t(" << wchar_t(ch) << ") ;\r\n";
      }
      std::wcout << L" #### end #### \r\n";
    };
  };

  //------------------------------------------------------------------------------------

  template<>
  puppyMain<wchar_t,wchar_t>::puppyMain(brainfuck::core *pCore)
  : m_pCore(pCore)
  {
    m_chResult = 0;
  };

  //------------------------------------------------------------------------------------

  template<>
  seakgChrysocyon::chrysocyonAnswer puppyMain<wchar_t, wchar_t>::SendElement(wchar_t ch)
  {
    if( ch == '>' )
    {
      m_pCore->next();
      if( m_pCore->Debug ) m_chResult = ch; else m_chResult = 0;
      return seakgChrysocyon::schsComplete;
    }
    else if( ch == '<' )
    {
      m_pCore->prev();
      if( m_pCore->Debug ) m_chResult = ch; else m_chResult = 0;
      return seakgChrysocyon::schsComplete;
    }
    else if( ch == '+' )
    {
      m_pCore->inc();
      if( m_pCore->Debug ) m_chResult = ch; else m_chResult = 0;
      return seakgChrysocyon::schsComplete;
    }
    else if( ch == '-' )
    {
      m_pCore->decr();
      if( m_pCore->Debug ) m_chResult = ch; else m_chResult = 0;
      return seakgChrysocyon::schsComplete;
    }
    else if( ch == '.' )
    {
      m_chResult = m_pCore->get();
      return seakgChrysocyon::schsComplete;
    }
    else if( ch == ',' )
    {
      int chTemp = wchar_t(getch());
      m_pCore->set(chTemp);
//      m_chResult = chTemp;
      if( m_pCore->Debug ) m_chResult = chTemp; else m_chResult = 0;
      return seakgChrysocyon::schsComplete;
    }
    else if( ch == '[' )
    {
      if( m_pCore->Debug ) m_chResult = ch; else m_chResult = 0;
      return seakgChrysocyon::schsComplete;
    }
    else if( ch == 'p' )
    {
      m_pCore->print_state();
      if( m_pCore->Debug ) m_chResult = ch; else m_chResult = 0;
      return seakgChrysocyon::schsComplete;
    }
    else if( ch == ']' )
    {
      if( m_pCore->Debug ) m_chResult = ch; else m_chResult = 0;
      return seakgChrysocyon::schsComplete;
    }
    else if( ch == '\r' )
    {
      if( m_pCore->Debug ) m_chResult = ch; else m_chResult = 0;
      return seakgChrysocyon::schsComplete;
    }
    else if( ch == '\n' )
    {
      if( m_pCore->Debug ) m_chResult = ch; else m_chResult = 0;
      return seakgChrysocyon::schsComplete;
    }

    return seakgChrysocyon::schsNone;
  };

  //------------------------------------------------------------------------------------

  template<>
  void puppyMain<wchar_t, wchar_t>::GetResult( seakgChrysocyon::Stack<wchar_t> *pStackResult )
  {
    pStackResult->Push( m_chResult );
  };

  //------------------------------------------------------------------------------------

  template<>
  void puppyMain<wchar_t, wchar_t>::Reset()
  {
    m_chResult = ' ';
  };

  //------------------------------------------------------------------------------------

  template<>
  bool puppyMain<wchar_t, wchar_t>::StepBack()
  {
    return false;
  };
//------------------------------------------------------------------------------------

/* schsNone = 0, // точно нет или я отказываюсь
		schsYetUnknown = 1, //еще не знаю или еще не определился давай дальше
		schsMaybe = 2, // Может быть мое
		schsOnlyMe = 3, // Точно мое ( и должно быть только мое )
		schsComplete = 4, // да я закончил можешь забирать результат */


//---------------------------------------------------------------------------
}; //namespace brainfuck

#pragma package(smart_init)


