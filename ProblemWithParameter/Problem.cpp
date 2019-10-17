#include "Problem.h"
#include "ILog.h"

#include <QString>
#include <math.h>
#include <string.h>

// Solve problem min of x^2 - 2 * a * x, where x is argument, a is parameter

#define CALC_VAL(arg, param) ((arg) * (arg) - 2 * (arg) * (param))

#define REPORT(MSG) \
    QString qmsg("[PROBLEM_PL6]:  "); \
    qmsg += QString(MSG); \
    qmsg += "\n\t\tFile: "; \
    qmsg += __FILE__; \
    qmsg += "\n\t\tLine: "; \
    qmsg += QString::number(__LINE__); \
    qmsg += "\n\t\tFunction: "; \
    qmsg += __FUNCTION__; \
    ILog::report(qmsg.toStdString().c_str())

extern "C" {
    SHARED_EXPORT void * getBrocker()
    {
        return (IBrocker *)(new Problem());
    }
}

#define CHECK_DIM(name) \
    if ((name) == NULL) \
        return ERR_WRONG_ARG; \
    if ((name)->getDim() != 1) \
        return ERR_DIMENSIONS_MISMATCH;

int Problem::goalFunction(IVector const* args, IVector const* params, double& res) const
{
    CHECK_DIM(args);
    CHECK_DIM(params);

    double arg, param;
    args->getCoord(0, arg);
    params->getCoord(0, param);

    res = CALC_VAL(arg, param);

    return ERR_OK;
}

int Problem::goalFunctionByArgs(IVector const* args, double& res) const
{
    if (m_params == NULL)
    {
        REPORT("Params was not set");
        return ERR_WRONG_ARG;
    }
    CHECK_DIM(args);
    double arg, param;
    args->getCoord(0, arg);
    m_params->getCoord(0, param);

    res = CALC_VAL(arg, param);

    return ERR_OK;
}


int Problem::goalFunctionByParams(IVector const*  params, double& res) const
{
    if (m_args == NULL)
    {
        REPORT("Arguments was not set");
        return ERR_WRONG_ARG;
    }
    CHECK_DIM(params);

    double arg, param;
    m_args->getCoord(0, arg);
    params->getCoord(0, param);

    res = CALC_VAL(arg, param);

    return ERR_OK;
}

int Problem::getArgsDim(size_t& dim) const
{
    dim = m_argsDim;
    return ERR_OK;
}

int Problem::getParamsDim(size_t& dim) const
{
    dim = m_paramsDim;
    return ERR_OK;
}

int Problem::setParams(IVector const* params)
{
    CHECK_DIM(params);
    delete m_params;
    m_params = params->clone();
    return ERR_OK;
}

int Problem::setArgs(IVector const* args)
{
    CHECK_DIM(args);
    delete m_args;
    m_args = args->clone();
    return ERR_OK;
}

int Problem::derivativeGoalFunction(size_t order, size_t idx, DerivedType dr, double& value,
                                    IVector const* args, IVector const* params) const
{
    if (order == 0)
        return goalFunction(args, params, value);

    CHECK_DIM(args);
    CHECK_DIM(params);

    if (idx != 0)
    {
        REPORT("Wrong idx");
        return ERR_WRONG_ARG;
    }

    double arg, param;
    args->getCoord(0, arg);
    params->getCoord(0, param);

    if (dr == BY_ARGS)
    {
        if (order == 1)
            value =  2 * arg - 2 * param;
        else if (order == 2)
            value = 2;
        else
            value = 0;

    } else if (dr == BY_PARAMS)
    {
        if (order == 1)
            value = -2 * arg;
        else
            value = 0;
    }
    else
    {
        REPORT("Wrong derivative type param");
        return ERR_WRONG_ARG;
    }

    return ERR_OK;
}

int Problem::derivativeGoalFunctionByArgs(size_t order, size_t idx, DerivedType dr, double& value, IVector const* args) const
{
    if (order == 0)
        return goalFunctionByArgs(args, value);

    if (m_params == NULL)
    {
        REPORT("Params was not set");
        return ERR_WRONG_ARG;
    }
    CHECK_DIM(args);

    if (idx != 0)
    {
        REPORT("Wrong idx");
        return ERR_WRONG_ARG;
    }

    double arg, param;
    args->getCoord(0, arg);
    m_params->getCoord(0, param);

    if (dr == BY_ARGS)
    {
        if (order == 1)
            value =  2 * arg - 2 * param;
        else if (order == 2)
            value = 2;
        else
            value = 0;

    } else if (dr == BY_PARAMS)
    {
        if (order == 1)
            value = -2 * arg;
        else
            value = 0;
    }
    else
    {
        REPORT("Wrong derivative type param");
        return ERR_WRONG_ARG;
    }

    return ERR_OK;
}

int Problem::derivativeGoalFunctionByParams(size_t order, size_t idx, DerivedType dr, double& value, IVector const* params) const
{
    if (order == 0)
        return goalFunctionByParams(params, value);

    if (m_args == NULL)
    {
        REPORT("Args was not set");
        return ERR_WRONG_ARG;
    }
    CHECK_DIM(params);

    if (idx != 0)
    {
        REPORT("Wrong idx");
        return ERR_WRONG_ARG;
    }

    double arg, param;
    m_args->getCoord(0, arg);
    params->getCoord(0, param);

    if (dr == BY_ARGS)
    {
        if (order == 1)
            value =  2 * arg - 2 * param;
        else if (order == 2)
            value = 2;
        else
            value = 0;

    } else if (dr == BY_PARAMS)
    {
        if (order == 1)
            value = -2 * arg;
        else
            value = 0;
    }
    else
    {
        REPORT("Wrong derivative type param");
        return ERR_WRONG_ARG;
    }

    return ERR_OK;
}

Problem::~Problem()
{
    delete m_args;
    delete m_params;
}

Problem::Problem() :
    m_paramsDim(1), m_argsDim(1),
    m_params(NULL), m_args(NULL)
{
}

bool Problem::canCastTo(Type type) const
{
    return type == IBrocker::PROBLEM;
}

void* Problem::getInterfaceImpl(Type type) const
{
    if (type == IBrocker::SOLVER)
    {
        return NULL;
    }
    return (IProblem *)(const_cast<Problem *>(this));
}

int Problem::release()
{
    delete m_args;
    delete m_params;

    m_args = NULL;
    m_params = NULL;
    return ERR_OK;
}
