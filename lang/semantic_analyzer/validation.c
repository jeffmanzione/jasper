#include "lang/semantic_analyzer/validation.h"

#include "debug/debug.h"
#include "lang/parser/lang_parser.h"
#include "lang/semantic_analyzer/definitions.h"

SemanticType compute_sematic_type(ExpressionTree *etree) {
  ASSERT(NOT_NULL(etree));
  SemanticType sem_type;
  // Replace with map lookup.
  if (IS_EXPRESSION(etree, constant)) {
    Expression_constant *constant = EXTRACT_EXPRESSION(etree, constant);
    sem_type.type = SQ_SINGLE;
    sem_type.single.entity_type = PRIMITIVE;
    sem_type.single.primitive_type = ptype(&constant->value);
  } else if (IS_EXPRESSION()) {
  }
  FATALF("Unknown expression.");
  return sem_type;
}