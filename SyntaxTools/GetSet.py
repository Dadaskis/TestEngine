while True:
    varData = input()
    varData = varData.split(" ")
    varType = varData[0]
    varName = varData[1]
    temp = list(varName)
    temp[0] = temp[0].upper()
    methodVarName = "".join(temp)
    print()
    print(varType + "& get" + methodVarName + "(){\n    return this->" + varName + ";\n}")
    print()
    print("void set" + methodVarName + "(const " + varType + "& " + varName + "){\n    this->" + varName + " = " + varName + ";\n}")
    print()