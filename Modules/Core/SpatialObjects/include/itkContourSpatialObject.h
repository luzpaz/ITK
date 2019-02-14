/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef itkContourSpatialObject_h
#define itkContourSpatialObject_h

#include <list>

#include "itkPointBasedSpatialObject.h"
#include "itkContourSpatialObjectPoint.h"

namespace itk
{
/**
 * \class ContourSpatialObject
 * \brief Representation of a Contour based on the spatial object classes.
 *
 * The Contour is basically defined by a set of points which are inside this
 * blob
 *
 * \sa SpatialObjectPoint
 * \ingroup ITKSpatialObjects
 */

template< unsigned int TDimension = 3 >
class ITK_TEMPLATE_EXPORT ContourSpatialObject:
  public PointBasedSpatialObject<  TDimension,
           ContourSpatialObjectPoint< TDimension > >
{
public:
  ITK_DISALLOW_COPY_AND_ASSIGN(ContourSpatialObject);

  using Self = ContourSpatialObject;
  using Superclass = PointBasedSpatialObject< TDimension >;
  using Pointer = SmartPointer< Self >;
  using ConstPointer = SmartPointer< const Self >;

  using ScalarType = double;

  using ContourPointType = typename SpatialObjectPoint< TDimension >;
  using ContourPointListType = std::vector< ContourPointType >;

  using PointType = typename Superclass::PointType;
  using TransformType = typename Superclass::TransformType;
  using BoundingBoxType = typename Superclass::BoundingBoxType;
  using PointContainerType = VectorContainer< IdentifierType, PointType >;
  using PointContainerPointer = SmartPointer< PointContainerType >;

  enum InterpolationMethodType {
    NO_INTERPOLATION = 0,
    EXPLICIT_INTERPOLATION,
    BEZIER_INTERPOLATION,
    LINEAR_INTERPOLATION };

  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Method for creation through the object factory. */
  itkTypeMacro(ContourSpatialObject, PointBasedSpatialObject);

  /** Returns a reference to the list of the control points. */
  ContourPointListType & GetControlPoints()
  { return m_ControlPoints; }

  /** Returns a reference to the list of the control points. */
  const ContourPointListType & GetControlPoints() const
  { return m_ControlPoints; }

  /** Set the list of control points. */
  void SetControlPoints(ContourPointListType & newPoints);

  /** Return a control point in the list given the index */
  const ContourPointType * GetControlPoint(IdentifierType id) const
  { return &( m_ControlPoints[id] ); }

  /** Return a control point in the list given the index */
  SpatialObjectPointType * GetControlPoint(IdentifierType id)
  { return &( m_ControlPoints[id] ); }

  /** Return the number of control points in the list */
  SizeValueType GetNumberOfControlPoints() const
  { return static_cast<SizeValueType>( m_ControlPoints.size() ); }

  /** Set the interpolation type */
  itkSetMacro( InterpolationMethod, InterpolationMethodType )

  /** Get the interpolation type */
  itkGetMacro( InterpolationMethod, InterpolationMethodType )

  /** Set the interpolation factor, e.g., factor of 2 means 2 interpolated
   *    points created for every control point. */
  itkSetMacro( InterpolationFactor, unsigned int )

  /** Get the interpolation factor */
  itkGetMacro( InterpolationFactor, unsigned int )

  /** Set if the contour is closed */
  itkSetMacro(IsClosed, bool);

  /** Get if the contour is closed */
  itkGetConstMacro(IsClosed, bool);

  /** Set the axis-normal orientation of the contour */
  itkSetMacro(OrientationInObjectSpace, int);

  /** Get the axis-normal orientation of the contour */
  itkGetConstMacro(OrientationInObjectSpace, int);

  /** Set the slice attached to the contour.
   *   Set -1 to indicate no attachment */
  itkSetMacro(AttachedToSlice, int);

  /** Get the slice attached to the contour.
   *   Return -1 if not attached. */
  itkGetConstMacro(AttachedToSlice, int);

  /** Apply the interpolator to generate points from the control points */
  void Update();

protected:

  ContourPointListType      m_ControlPoints;

  InterpolationMethodType   m_InterpolationMethod;
  unsigned int              m_InterpolationFactor;

  bool                      m_IsClosed;
  int                       m_OrientationInObjectSpace;
  int                       m_AttachedToSlice;

  ContourSpatialObject();
  ~ContourSpatialObject() override = default;

  /** Method to print the object. */
  void PrintSelf(std::ostream & os, Indent indent) const override;
};
} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkContourSpatialObject.hxx"
#endif

#endif // itkContourSpatialObject_h
