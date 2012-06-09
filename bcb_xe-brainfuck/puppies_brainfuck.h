//---------------------------------------------------------------------------

#ifndef puppies_brainfuckH
#define puppies_brainfuckH

#include <vector.h>
#include <vcl.h>
#include <conio.h>
#include "../seakgChrysocyonParser/bcb_xe.h"

namespace brainfuck
{
  class core
  {
    public:
      core();
      void next();  // >
      void prev();  // <
      void inc(); // +
      void decr(); // -
      int  get(); // .
      void set(int ch); // ,

      void print_state();
      bool Debug;
    private:
      vector<int> m_vSlots;
      int m_nPos;
  };


  template<typename Element, typename ArrayOfElement>
  class puppyMain : public seakgChrysocyon::InterfaceChrysocyonPuppy<Element,ArrayOfElement>
  {
    public:
      puppyMain(brainfuck::core *pCore);
      // InterfaceChrysocyonPuppy
      virtual seakgChrysocyon::chrysocyonAnswer SendElement(Element ch);
      virtual void GetResult( seakgChrysocyon::Stack<ArrayOfElement> *pStackResult );
      virtual void Reset();
      virtual bool StepBack();

    private:
      wchar_t m_chResult;
      brainfuck::core *m_pCore;
  };

/*
  template <>
  class brainfuckPuppyMain<wchar_t,wchar_t>
  {
    public:
      brainfuckPuppyMain(brainfuck::core *pCore);

      // InterfaceChrysocyonPuppy
      virtual seakgChrysocyon::chrysocyonAnswer SendElement(wchar_t ch);
      virtual void GetResult( seakgChrysocyon::Stack<wchar_t> *pStackResult );
      virtual void Reset();
      virtual bool StepBack();

    private:
      wchar_t m_chResult;
      brainfuck::core *m_pCore;
  };
*/

}; // namespace brainfuck

//---------------------------------------------------------------------------
#endif
