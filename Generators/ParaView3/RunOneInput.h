vtkInformation *inInfo = inputVector[0]->GetInformationObject(0);
vtkImageData *input = vtkImageData::SafeDownCast
  (inInfo->Get(vtkDataObject::DATA_OBJECT()));
if (!input)
  {
  vtkErrorMacro("Input is not of type vtkImageData");
  return 0;
  }

vtkInformation *outInfo = outputVector->GetInformationObject(0);
vtkImageData *output = vtkImageData::SafeDownCast
  (outInfo->Get(vtkDataObject::DATA_OBJECT()));
if (!output)
  {
  vtkErrorMacro("Output is not of type vtkImageData");
  return 0;
  }

switch ( input->GetScalarType() )
  {
  //vtkReducedTypeTemplateMacro( Run( static_cast< VTK_TT *>( 0 ),
  //input, output ); );
#ifdef ITK_UCHAR_TYPE
  case VTK_UNSIGNED_CHAR:
    Run( static_cast< unsigned char * >( 0 ), input, output );
    break;
#endif
#ifdef ITK_CHAR_TYPE
  case VTK_CHAR:
  case VTK_SIGNED_CHAR:
    Run( static_cast< char * >( 0 ), input, output );
    break;
#endif
#ifdef ITK_USHORT_TYPE
  case VTK_UNSIGNED_SHORT:
    Run( static_cast< unsigned short * >( 0 ), input, output );
    break;
#endif
#ifdef ITK_SHORT_TYPE
  case VTK_SHORT:
    Run( static_cast< short * >( 0 ), input, output );
    break;
#endif
#ifdef ITK_UINT_TYPE
  case VTK_UNSIGNED_INT:
    Run( static_cast< unsigned int * >( 0 ), input, output );
    break;
#endif
#ifdef ITK_INT_TYPE
  case VTK_INT:
    Run( static_cast< int * >( 0 ), input, output );
    break;
#endif
#ifdef ITK_ULONG_TYPE
  case VTK_UNSIGNED_LONG:
    Run( static_cast< unsigned long * >( 0 ), input, output );
    break;
#endif
#ifdef ITK_LONG_TYPE
  case VTK_LONG:
    Run( static_cast< long * >( 0 ), input, output );
    break;
#endif
#ifdef ITK_FLOAT_TYPE
  case VTK_FLOAT:
    Run( static_cast< float * >( 0 ), input, output );
    break;
#endif
#ifdef ITK_DOUBLE_TYPE
  case VTK_DOUBLE:
    Run( static_cast< double * >( 0 ), input, output );
    break;
#endif

  default:
    vtkErrorMacro( "Unknown pixel type encountered" );
    break;
  }