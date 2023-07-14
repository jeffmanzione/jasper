#ifndef LANG_SEMANTIC_ANALYZER_VALIDATION_H_
#define LANG_SEMANTIC_ANALYZER_VALIDATION_H_

#include "entity/entity.h"
#include "lang/semantic_analyzer/expression_tree.h"

typedef struct {
  EntityType entity_type;
  union {
    PrimitiveType primitive_type;
    Class *object_type;
  };
} SingleType;

typedef enum {
  SQ_UNKNOWN = 0,
  SQ_SINGLE = 1,
  SQ_MULTIPLE = 2
} SemanticQuantityType;

typedef struct {
  SemanticQuantityType type;
  union {
    SingleType single;
    AList multi;
  };
} SemanticType;

SemanticType compute_sematic_type(ExpressionTree *etree);

#endif /* LANG_SEMANTIC_ANALYZER_VALIDATION_H_ */