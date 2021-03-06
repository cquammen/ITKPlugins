vtkInformation *inInfo = inputVector[0]->GetInformationObject(0);
vtkImageData *originalInput = vtkImageData::SafeDownCast
  (inInfo->Get(vtkDataObject::DATA_OBJECT()));
if (!originalInput)
  {
  vtkErrorMacro("Input is not of type vtkImageData");
  return 0;
  }

vtkImageData *input = originalInput;

vtkInformation *outInfo = outputVector->GetInformationObject(0);
vtkImageData *output = vtkImageData::SafeDownCast
  (outInfo->Get(vtkDataObject::DATA_OBJECT()));
if (!output)
  {
  vtkErrorMacro("Output is not of type vtkImageData");
  return 0;
  }

// Set the active scalar array in the inputs. Normally, this would be
// done in the filter that imports the VTK image into ITK, but that
// filter doesn't expose a way to set the active scalar in the interface.
char * activeArrayName0 = this->GetInputArrayToProcess( 0, input )->GetName();
input->GetPointData()->SetActiveScalars( activeArrayName0 );

bool success = true;
switch( input->GetPointData()->GetScalars()->GetDataType() )
  {
#ifdef ITK_UCHAR_TYPE
  case VTK_UNSIGNED_CHAR:
    success = Run( static_cast< unsigned char * >( 0 ), input, output );
    break;
#endif
#ifdef ITK_CHAR_TYPE
  case VTK_CHAR:
  case VTK_SIGNED_CHAR:
    success = Run( static_cast< char * >( 0 ), input, output );
    break;
#endif
#ifdef ITK_USHORT_TYPE
  case VTK_UNSIGNED_SHORT:
    success = Run( static_cast< unsigned short * >( 0 ), input, output );
    break;
#endif
#ifdef ITK_SHORT_TYPE
  case VTK_SHORT:
    success = Run( static_cast< short * >( 0 ), input, output );
    break;
#endif
#ifdef ITK_UINT_TYPE
  case VTK_UNSIGNED_INT:
    success = Run( static_cast< unsigned int * >( 0 ), input, output );
    break;
#endif
#ifdef ITK_INT_TYPE
  case VTK_INT:
    success = Run( static_cast< int * >( 0 ), input, output );
    break;
#endif
#ifdef ITK_ULONG_TYPE
  case VTK_UNSIGNED_LONG:
    success = Run( static_cast< unsigned long * >( 0 ), input, output );
    break;
#endif
#ifdef ITK_LONG_TYPE
  case VTK_LONG:
    success = Run( static_cast< long * >( 0 ), input, output );
    break;
#endif
#ifdef ITK_FLOAT_TYPE
  case VTK_FLOAT:
    success = Run( static_cast< float * >( 0 ), input, output );
    break;
#endif
#ifdef ITK_DOUBLE_TYPE
   case VTK_DOUBLE:
    success = Run( static_cast< double * >( 0 ), input, output );
    break;
#endif

  default:
    vtkErrorMacro( "Unknown pixel type encountered" );
    success = false;
    break;
  }
