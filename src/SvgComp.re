[@react.component]
let make = (~size) => {
  let style = ReactDOMRe.Style.make(~width=size, ~height=size, ());
  let box =
    Box.create(
      Vector.create(0., 0.),
      Vector.create(250., 0.),
      Vector.create(0., 250.),
    );
  let fishp = Magic.createPicture(Fish.fish);
  let p = Picture.squareLimit(3, fishp);
  let rendered = p(box);
  let mirrored = Mirror.mirror(250., rendered);
  let elements = List.map(Svg.toElement, mirrored);
  let lines = Svg.lines(elements);
  let polygons = Svg.polygons(elements);
  let polylines = Svg.polylines(elements);
  let paths = Svg.paths(elements);
  let linesArray = [||];
  let polygonsArray = [||];
  let polylinesArray = [||];
  let pathsArray = [||];
  for (i in 0 to 250) {
    linesArray->Array.set(
      i,
      <line
        x1={lines->List.nth(i).x1}
        y1={lines->List.nth(i).y1}
        x2={lines->List.nth(i).x2}
        y2={lines->List.nth(i).y2}
        stroke={lines->List.nth(i).stroke}
      />,
    );
    polygonsArray->Array.set(
      i,
      <polygon
        points={polygons->List.nth(i).points}
        stroke={polygons->List.nth(i).stroke}
        strokeWidth={polygons->List.nth(i).strokeWidth}
        fill="None"
      />,
    );
    polylinesArray->Array.set(
      i,
      <polygon
        points={polylines->List.nth(i).points}
        stroke={polylines->List.nth(i).stroke}
        strokeWidth={polylines->List.nth(i).strokeWidth}
        fill="None"
      />,
    );
    pathsArray->Array.set(
      i,
      <path
        d={paths->List.nth(i).d}
        stroke={paths->List.nth(i).stroke}
        strokeWidth={paths->List.nth(i).strokeWidth}
        fill="None"
      />,
    );
  };
  <svg style xmlns="http://www.w3.org/2000/svg">
    linesArray->React.array
    polygonsArray->React.array
    polylinesArray->React.array
    pathsArray->React.array
  </svg>;
};