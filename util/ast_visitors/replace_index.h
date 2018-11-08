/*****************************************************************************

    This file is part of Modelica C Compiler.

    Modelica C Compiler is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Modelica C Compiler is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Modelica C Compiler.  If not, see <http://www.gnu.org/licenses/>.

******************************************************************************/

#ifndef AST_VISITOR_REPLACEINDEX
#define AST_VISITOR_REPLACEINDEX
#include <boost/variant/static_visitor.hpp>
#include <boost/functional/hash.hpp>
#include <ast/expression.h>
#include <util/table.h>
#include <unordered_map>

namespace Modelica {

  using namespace Modelica::AST;
  class ReplaceIndex: public boost::static_visitor<Expression> {
  public:
    ReplaceIndex(const VarSymbolTable &, bool eval=false);
    Expression operator()(Integer v) const;
    Expression operator()(Real v) const;
    Expression operator()(Boolean v) const;
    Expression operator()(String v) const;
    Expression operator()(Name v) const;
    Expression operator()(Expression v) const;
    Expression operator()(SubEnd v) const;
    Expression operator()(SubAll v) const;
    Expression operator()(BinOp) const;
    Expression operator()(UnaryOp) const;
    Expression operator()(Brace) const;
    Expression operator()(Bracket) const;
    Expression operator()(Call) const;
    Expression operator()(FunctionExp) const;
    Expression operator()(ForExp);
    Expression operator()(IfExp) const;
    Expression operator()(Named) const;
    Expression operator()(Output) const;
    Expression operator()(Reference) const;
    Expression operator()(Range) const;
    const VarSymbolTable &vtable; 
    bool eval_parameters;
  private:
		std::unordered_map <std::pair< Expression, Indexes>, int, boost::hash<std::pair< Expression, Indexes>>> reference_names;
		std::unordered_map < Expression , int, boost::hash<Expression>> reference_names2;
		int counter;
  }; 
}
#endif // AST_VISITOR_REPLACEINDEX
